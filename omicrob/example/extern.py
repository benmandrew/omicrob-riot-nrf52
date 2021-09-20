
from typing import List

RUNTIMEINCLUDESTR = "/omicrob/src/byterun/vm/runtime.c>"
BYTECODESTR = "PROGMEM void * const ocaml_primitives[OCAML_PRIMITIVE_NUMBER]"

VARIABLES = [
  "ocaml_stack", "ocaml_ram_heap", "ocaml_ram_global_data",
  "ocaml_flash_heap", "ocaml_initial_static_heap",
  "ocaml_initial_stack", "ocaml_flash_global_data",
  "ocaml_bytecode", "ocaml_primitives"]

def getCamlPrimitives(ls: List[str]) -> List[str]:
  idx = ls.index(next((l for l in ls if BYTECODESTR in l), None))
  l = ls[idx + 1:-2]
  splits = [r.split("&") for r in l]
  for split in splits:
    if len(split) != 2:
      print("Malformed primitive:", split)
      raise Exception
  return [split[1][:-1] for split in splits]

def insertExternalSymbols(ls: List[str]) -> List[str]:
  symbols = getCamlPrimitives(ls)
  idx = ls.index(next((l for l in ls if RUNTIMEINCLUDESTR in l), None))
  ext = ["extern value {}();".format(symbol) for symbol in symbols]
  return ls[:idx + 1] + ext + ls[idx + 1:]

def extractHeader(ls: List[str], variable: str) -> str:
  line = next((l for l in ls if variable in l), None)
  i = ls.index(line)
  if "{" in line:
    # ls[i] = "{} = {{".format(variable)
    return line.replace(" = {", ";")
  else:
    ls[i] = ""
    return line

def createHeaderFile(ls: List[str]) -> None:
  defineIdx = ls.index("value ocaml_stack[OCAML_STACK_WOSIZE];")
  defines = ls[:defineIdx]
  # declarations = [extractHeader(ls, var) for var in variables]
  # s = "\n".join(defines + declarations)
  s = "\n".join(["#ifndef __TEST_DEF__", "#define __TEST_DEF__"] + defines + ["#endif"])
  with open("example/test_def.h", "w") as f:
    f.write(s)
  return defineIdx

def main():
  s = ""
  with open("example/test.c", "r") as f:
    s = f.read().split("\n")
  n = insertExternalSymbols(s)

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

