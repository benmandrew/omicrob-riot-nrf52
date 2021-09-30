# omicrob-riot-nrf52

This project gets OCaml bytecode running on the nRF52840 board. It uses OMicroB for the runtime and bytecode optimisation, and RIOT OS for the base layer between the runtime and the board, as well as for its robust build system.

This is an offshoot of [**ocaml-riot-nrf52**](https://github.com/benmandrew/ocaml-riot-nrf52 "ocaml-riot-nrf52"), which uses the standard OCaml runtime instead of OMicroB. This led to overly large images as well as issues with dynamic memory allocation that prevented the usage of OCaml modules. **ocaml-riot-nrf52** is kept public as it is still useful to learn from.

This project is currently not working, as OMicroB and its dependencies target OCaml 4.07, while I am targeting 4.12. Between 4.07 and 4.12 there was a significant change in the structure of closure environments, which prevents 4.12 bytecode functions from being called by 4.07 OMicroB. Without functions the image is produced correctly, but obviously non-trivial programs need functions.

The projects that need to be updated to 4.12 are:
- OMicroB
- OcamlClean
- OByteLib

## Building

```
git clone https://github.com/benmandrew/omicrob-riot-nrf52.git
cd omicrob-riot-nrf52/omicrob
./configure
make
```
