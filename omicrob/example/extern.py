
from typing import List

## Strings to split the file on
RUNTIMEINCLUDESTR = "/omicrob/src/byterun/vm/runtime.c>"
PRIMITIVESTR = "PROGMEM void * const ocaml_primitives[OCAML_PRIMITIVE_NUMBER]"

## Variables that we want to extract out to <file>_ext.h
VARIABLES = [
  "ocaml_stack", "ocaml_ram_heap", "ocaml_ram_global_data",
  "ocaml_flash_heap", "ocaml_initial_static_heap",
  "ocaml_initial_stack", "ocaml_flash_global_data",
  "ocaml_bytecode", "ocaml_primitives"]

## Get the list of caml C primitive functions
def getPrimitives(lines: List[str]) -> List[str]:
  ## Find the declaration of the primitives array
  idx = lines.index(next((l for l in lines if PRIMITIVESTR in l), None))
  ## Find the end of the array
  line = lines[idx + 1:-2]
  ## Get the name of each function without comments or & symbol
  splits = [r.split("&") for r in line]
  for split in splits:
    if len(split) != 2:
      print("Malformed primitive:", split)
      raise Exception
  return [split[1][:-1] for split in splits]

## Insert the C primitive functions as externally defined symbols,
## so that they can be linked in later without the compiler complaining
def externalisePrimitives(lines: List[str]) -> List[str]:
  symbols = getPrimitives(lines)
  ## Insert in the location next to the runtime preprocessor include
  idx = lines.index(next((l for l in lines if RUNTIMEINCLUDESTR in l), None))
  ext = ["extern value {}();".format(symbol) for symbol in symbols]
  return lines[:idx + 1] + ext + lines[idx + 1:]

## Extract the preprocessor defines into their own file
def createHeaderFile(ls: List[str]) -> int:
  defineIdx = ls.index("value ocaml_stack[OCAML_STACK_WOSIZE];")
  defines = ls[:defineIdx]
  s = "\n".join(["#ifndef __TEST_DEF__", "#define __TEST_DEF__"] + defines + ["#endif"])
  with open("example/test_def.h", "w") as f:
    f.write(s)
  return defineIdx

def main():
  s: List[str] = []
  with open("example/test.c", "r") as f:
    s = f.read().split("\n")
  n = externalisePrimitives(s)

  defineIdx = createHeaderFile(n)

  out = "#ifndef __TEST_EXT__\n#define __TEST_EXT__\n\n{}\n#endif".format(
    "\n".join(
      [
        "#include \"../ocaml/runtime/caml/compatibility.h\"",
        "#include \"test_def.h\""
        ] + n[defineIdx:]))

  with open("example/test_ext.h", "w") as f:
    f.write(out)

if __name__ == "__main__":
  main()

