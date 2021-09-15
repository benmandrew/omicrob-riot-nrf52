# name of your application
APPLICATION = omicrob-nrf52

# This has to be the absolute path to the RIOT base directory:
RIOTBASE ?= $(CURDIR)/..
BINDIR ?= $(CURDIR)/bin/nrf52840-mdk
export RUNTIMEDIR ?= $(CURDIR)/src/byterun

# Comment this out to disable code in RIOT that does safety checking
# which is not needed in a production environment but helps in the
# development process:
DEVELHELP ?= 1

# Change this to 0 show compiler invocation lines by default:
QUIET ?= 0

BOARD=nrf52840-mdk

# USEMODULE += xtimer

export APPDIR = $(CURDIR)/example

# LINKFLAGS = $(OCAMLDIR)/runtime/libcamlrun.a -lm

include $(RIOTBASE)/Makefile.include

# CFLAGS := $(subst \",",$(CFLAGS))
# CFLAGS := $(subst ',,$(CFLAGS))
CFLAGS := $(subst -Wall,,$(CFLAGS))
CFLAGS := $(subst -Werror,,$(CFLAGS))
CFLAGS := $(subst -Wstrict-prototypes,,$(CFLAGS))
CFLAGS := $(subst -Wextra,,$(CFLAGS))
CFLAGS := $(subst -Wold-style-definition,,$(CFLAGS))
CFLAGS := $(subst -O3,,$(CFLAGS))
CFLAGS := $(subst -O2,,$(CFLAGS))
CFLAGS := $(subst -O1,,$(CFLAGS))
CFLAGS += -Wno-format-nonliteral -Wno-strict-prototypes -lm -s

# ----------------------------------------------------------------------------

include etc/Makefile.conf

all: internals $(TARGETS)

internals: config
#	$(call compile, lib/extra)
	$(call compile, src/bc2c)
#	$(call compile, src/h15ppx)
#	$(call compile, src/simulators/lcd)
#	$(call compile, src/simulators/lcd_16x2)
#	$(call compile, src/simulators/dip)
#	$(call compile, src/simulators/circuit)
	$(call compile, src/byterun)
	$(call compile, src/omicrob)
#	$(call compile, ../RIOT-copy/ocaml-nrf52/ocaml/stdlib)
#	$(call compile, src/stdlib)

riot:
	$(MAKE) -C $(RIOTBASE) -f Makefile.include link CFLAGS='$(CFLAGS)'

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

# install: all
# 	mkdir -p "$(LIBDIR)"
# 	mkdir -p "$(LIBEXECDIR)"
# 	mkdir -p "$(INCLUDEDIR)"
# 	mkdir -p "$(BINDIR)"
# 	mkdir -p "$(MAN1DIR)"
# 	mkdir -p "$(MAN3DIR)"
# 	cp bin/bc2c "$(BINDIR)/bc2c"
# 	cp bin/h15ppx "$(BINDIR)/h15ppx"
# 	cp bin/omicrob "$(BINDIR)/omicrob"
# 	cp bin/*_simulator "$(LIBEXECDIR)/"
# 	cp doc/bc2c.1 "$(MAN1DIR)/bc2c.1"
# 	cp doc/omicrob.1 "$(MAN1DIR)/omicrob.1"
# 	cp lib/stdlib.cma "$(LIBDIR)/stdlib.cma"
# 	cp lib/libcamlrun.a "$(LIBDIR)/libcamlrun.a"
# 	cp lib/*.ml "$(LIBDIR)/"
# 	cp lib/*.mli "$(LIBDIR)/"
# 	cp lib/*.cmo "$(LIBDIR)/"
# 	cp lib/*.cmi "$(LIBDIR)/"
# 	cp lib/lcd_cgrom.txt "$(LIBDIR)/"
# 	cp -a lib/extra "$(LIBDIR)/"
# 	cp -a lib/targets "$(LIBDIR)/"
# 	cp -a src/byterun/vm "$(INCLUDEDIR)/"
# 	cp -a src/byterun/prims "$(INCLUDEDIR)/"
# 	cp -a src/byterun/simul "$(INCLUDEDIR)/"
# 	cp -a src/byterun/avr "$(INCLUDEDIR)" 2> /dev/null
# 	cp -a src/byterun/pic32 "$(INCLUDEDIR)/" 2> /dev/null
# 	cp -a src/byterun/stdlib "$(INCLUDEDIR)/"

# uninstall:
# 	-rm -f "$(BINDIR)/bc2c"
# 	-rm -f "$(BINDIR)/h15ppx"
# 	-rm -f "$(BINDIR)/omicrob"
# 	-rm -f "$(MAN1DIR)/omicrob.1"
# 	-rm -f "$(MAN1DIR)/bc2c.1"
# 	-rm -f "$(LIBDIR)/stdlib.cma"
# 	-rm -f "$(LIBDIR)/libcamlrun.a"
# 	-rm -f "$(LIBDIR)/"*.ml
# 	-rm -f "$(LIBDIR)/"*.mli
# 	-rm -f "$(LIBDIR)/"*.cmi
# 	-rm -f "$(LIBDIR)/"*.cmo
# 	-rm -f "$(LIBDIR)/lcd_cgrom.txt"
# 	-rm -rf "$(LIBDIR)/extra"
# 	-rm -f "$(LIBEXECDIR)/"*_simulator
# 	-rm -f "$(INCLUDEDIR)/vm/"*
# 	-rm -f "$(INCLUDEDIR)/prims/"*
# 	-rm -f "$(INCLUDEDIR)/simul/"*
# 	-rm -rf "$(INCLUDEDIR)/$(TARGET)/"*
# 	-rm -f "$(INCLUDEDIR)/stdlib/"*
# 	@for mod in $(MAN_3P_BASES); do \
# 	  rm -f "$(MAN3DIR)/"$$mod.3p;	\
# 	done
# 	@for mod in $(MAN_3O_BASES); do \
# 	  rm -f "$(MAN3DIR)/"$$mod.3o;	\
# 	done
# 	@if [ -d "$(LIBDIR)" ]; then rmdir "$(LIBDIR)"; fi
# 	@if [ -d "$(LIBEXECDIR)" ]; then rmdir "$(LIBEXECDIR)"; fi
# 	@if [ -d "$(INCLUDEDIR)/vm" ]; then rmdir "$(INCLUDEDIR)/vm"; fi
# 	@if [ -d "$(INCLUDEDIR)/prims" ]; then rmdir "$(INCLUDEDIR)/prims"; fi
# 	@if [ -d "$(INCLUDEDIR)/simul" ]; then rmdir "$(INCLUDEDIR)/simul"; fi
# 	@if [ -d "$(INCLUDEDIR)/$(TARGET)" ]; then rmdir "$(INCLUDEDIR)/$(TARGET)"; fi
# 	@if [ -d "$(INCLUDEDIR)/stdlib" ]; then rmdir "$(INCLUDEDIR)/stdlib"; fi
# 	@if [ -d "$(INCLUDEDIR)" ]; then rmdir "$(INCLUDEDIR)"; fi

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
	$(call clean, src/h15ppx)
	$(call clean, src/byterun)
	$(call clean, src/simulators/dip)
	$(call clean, src/simulators/lcd_16x2)
	$(call clean, src/simulators/lcd)
	$(call clean, src/simulators/circuit)
	$(call clean, src/omicrob)
#	$(call clean, ../RIOT-copy/ocaml-nrf52/ocaml/stdlib)
#	$(call clean, src/stdlib)
#	$(call clean, lib/extra)
	$(call clean, targets/avr)
	$(call clean, targets/pic32)

example:
	./bin/omicrob -v -c example/test.ml
	./bin/omicrob -v example/test.cmo -o example/test.byte
	./bin/omicrob -v example/test.byte -o example/test.c
	python3 example/extern.py
	rm example/test.c
	cp src/byterun/simul/arch-specific.c example/arch-specific.c
#	./bin/omicrob -v example/test.c -o example/test.elf
	$(MAKE) riot

exampleclean:
	rm -f example/test.byte example/test.cmo example/test.cmi \
		example/test.c example/arch-specific.c example/test_def.h \
		example/test_ext.h

.PHONY: all config install uninstall tests clean example exampleclean
