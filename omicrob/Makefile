# name of your application
APPLICATION = omicrob-nrf52

# This has to be the absolute path to the RIOT base directory:
RIOTBASE ?= $(CURDIR)/..
BINDIR ?= $(CURDIR)/bin/nrf52840-mdk
export RUNTIMEDIR ?= $(CURDIR)/src/byterun
export OCAMLDIR ?= $(CURDIR)/ocaml

# Comment this out to disable code in RIOT that does safety checking
# which is not needed in a production environment but helps in the
# development process:
DEVELHELP ?= 1

# Change this to 0 show compiler invocation lines by default:
QUIET ?= 0

BOARD = nrf52840-mdk
USEMODULE += xtimer

export APPDIR = $(CURDIR)/example

include $(RIOTBASE)/Makefile.include

# CFLAGS := $(subst \",",$(CFLAGS))
CFLAGS := $(subst ',,$(CFLAGS))
CFLAGS := $(subst -Wall,,$(CFLAGS))
CFLAGS := $(subst -Werror,,$(CFLAGS))
CFLAGS := $(subst -Wstrict-prototypes,,$(CFLAGS))
CFLAGS := $(subst -Wextra,,$(CFLAGS))
CFLAGS := $(subst -Wold-style-definition,,$(CFLAGS))
CFLAGS := $(subst -O3,,$(CFLAGS))
CFLAGS := $(subst -O2,,$(CFLAGS))
CFLAGS := $(subst -O1,,$(CFLAGS))
CFLAGS += -Wno-format-nonliteral -Wno-strict-prototypes -lm -s --specs=nosys.specs

## For whatever reason the CFLAGS get duplicated which causes issues (specifically in --specs=nosys.specs), so just filter out duplicates
uniq = $(if $1,$(firstword $1) $(call uniq,$(filter-out $(firstword $1),$1)))
UNIQ_CFLAGS = ${call uniq, ${CFLAGS}}

# MAKECONF_CFLAGS = -Wno-format-nonliteral -mno-thumb-interwork -mcpu=cortex-m4 -mlittle-endian \
# -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -ffunction-sections -fdata-sections -fno-builtin \
# -fshort-enums -ggdb -g3 -Os -DCPU_MODEL_NRF52840XXAA -DCPU_CORE_CORTEX_M4F \
# -DBOARD_NRF52840_MDK=\"nrf52840-mdk\" -DRIOT_BOARD=BOARD_NRF52840_MDK -DCPU_FAM_NRF52 \
# -DCPU_NRF52=\"nrf52\" -DRIOT_CPU=CPU_NRF52 -DMCU_NRF52=\"nrf52\" -DRIOT_MCU=MCU_NRF52 \
# -fwrapv -fno-common -ffunction-sections -fdata-sections -fno-delete-null-pointer-checks \
# -fdiagnostics-color -gz -Wformat=2 --specs=nosys.specs
MAKECONF_CC = arm-none-eabi-gcc
MAKECONF_LD = arm-none-eabi-gcc
MAKECONF_BUILD_ARCH = arm

STDLIB_DIR := src/stdlib
STDLIB_FILES := $(wildcard $(STDLIB_DIR)/*.mli) $(wildcard $(STDLIB_DIR)/*.ml)
STDLIB_OBJS := $(patsubst $(STDLIB_DIR)/%.mli,$(STDLIB_DIR)/%.cmi,$(STDLIB_FILES))
STDLIB_OBJS := $(patsubst $(STDLIB_DIR)/%.ml,$(STDLIB_DIR)/%.cmo,$(STDLIB_OBJS))

# ----------------------------------------------------------------------------

include etc/Makefile.conf
 
all: internals $(TARGETS)

internals: config
	mkdir -p bin/nrf52840-mdk/riotbuild
	cp stubs/riotbuild.h bin/nrf52840-mdk/riotbuild/riotbuild.h
#	$(call compile, lib/extra)
	$(call compile, src/bc2c)
	$(call compile, src/byterun)
	$(call compile, src/omicrob)
	$(call compile, src/stdlib)
	$(MAKE) example
	$(MAKE) ocaml
	$(MAKE) riot

riot:
	$(MAKE) -C $(RIOTBASE) -f Makefile.include link CFLAGS="$(UNIQ_CFLAGS)"

example:
	./bin/omicrob -v -c example/test.ml
	./bin/omicrob -v example/test.cmo -o example/test.byte
	./bin/omicrob -v example/test.byte -o example/test.c
	python3 example/extern.py
	rm example/test.c
	cp src/byterun/simul/arch-specific.c example/arch-specific.c

## ------------------------------------------------------------------------------

ocaml: ocaml/Makefile.config ocaml/runtime/caml/version.h
	$(MAKE) -C ocaml/runtime libcamlrun.a ARCH=arm APPLICATION=$(APPLICATION) CFLAGS="$(UNIQ_CFLAGS)"

ocaml/Makefile:
	sed -i -e 's/runtime\/ocamlrun tools/$$(CAMLRUN) tools/g' ocaml/Makefile
	sed -i -e 's!ASPPFLAGS =!ASPPFLAGS = $(CFLAGS)!g' ocaml/runtime/Makefile
	sed -i -e 's/otherlibraries="dynlink"/otherlibraries=""/g' ocaml/configure
	sed -i -e 's/oc_cflags="/oc_cflags="$$OC_CFLAGS /g' ocaml/configure
	sed -i -e 's/ocamlc_cflags="/ocamlc_cflags="$$OCAMLC_CFLAGS /g' ocaml/configure


ocaml/Makefile.config: ocaml/Makefile
	cd ocaml && \
		CC="$(MAKECONF_CC)" \
		CFLAGS="$(UNIQ_CFLAGS)" \
		AS="$(MAKECONF_AS)" \
		ASPP="$(MAKECONF_CC) -c" \
		ASPPFLAGS="$(ASPPFLAGS)" \
		LIBS="$(OC_LIBS)"\
		LD="$(MAKECONF_LD)" \
		SYSTEM="eabi" \
		MODEL="none" \
		CAMLRUN="$(CAMLRUN)" \
	  ./configure \
		-host=$(MAKECONF_BUILD_ARCH)-none-eabi \
		-disable-shared\
		-disable-systhreads\
		-disable-unix-lib\
		-disable-instrumented-runtime
	echo "ARCH=$(MAKECONF_OCAML_BUILD_ARCH)" >> ocaml/Makefile.config
	echo '#undef HAS_SOCKETS' >> ocaml/runtime/caml/s.h
	echo '#undef OCAML_OS_TYPE' >> ocaml/runtime/caml/s.h
	echo '#define OCAML_OS_TYPE "None"' >> ocaml/runtime/caml/s.h

ocaml/runtime/caml/version.h: ocaml/Makefile.config
	ocaml/tools/make-version-header.sh > $@

## ------------------------------------------------------------------------------




avr: internals
	$(call compile, targets/avr)

pic32: internals
	$(call compile, targets/pic32)

config:
	@if [ $(ETC)/Makefile.conf -ot VERSION -o                     \
             $(ETC)/Makefile.conf -ot configure ]; then               \
          echo 'Configuration files are not up to date.' 1>&2;        \
	  echo 'Please run `./configure` (with right options).' 1>&2; \
          exit 1;                                                     \
	fi

etc/Makefile.conf:
	@echo "You must run ./configure before" 1>&2
	@exit 1

tests: all
	@make --no-print-directory -C tests

clean:
	@rm -f *~ */*~ */*/*~ */*/*/*~
	@rm -rf $(BINDIR)/*
	@rm -f bin/omicrob
	$(call clean, src/bc2c)
	$(call clean, src/byterun)
	$(call clean, src/omicrob)
	$(call clean, src/stdlib)
#	$(call clean, lib/extra)
	$(call clean, targets/avr)
	$(call clean, targets/pic32)
	$(MAKE) exampleclean
	$(MAKE) -C ocaml clean
	rm -f src/stdlib/*.cmi src/stdlib/*.cmo

exampleclean:
	rm -f example/test.byte example/test.cmo example/test.cmi \
		example/test.c example/arch-specific.c example/test_def.h \
		example/test_ext.h

.PHONY: all config install uninstall tests clean example exampleclean
