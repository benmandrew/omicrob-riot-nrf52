
from typing import List

SEARCHSTRING = "#include </home/ben/omicrob-riot-nrf52/omicrob/src/byterun/vm/runtime.c>"

variables = [
  "ocaml_stack", "ocaml_ram_heap", "ocaml_ram_global_data",
  "ocaml_flash_heap", "ocaml_initial_static_heap",
  "ocaml_initial_stack", "ocaml_flash_global_data",
  "ocaml_bytecode", "ocaml_primitives"]

def getCamlPrimitives(s: str) -> List[str]:
  idx = s.find(SEARCHSTRING)
  l = s[idx + len(SEARCHSTRING):].split(",\n")[:-1]
  return [r.split("&")[1] for r in l]

def generateExternalSymbols(symbols: List[str]) -> str:
  return "\n".join(
    ["extern value {}();".format(symbol) for symbol in symbols])

def insertExternalSymbols(s: str) -> str:
  symbols = getCamlPrimitives(s)
  sp = s.split(SEARCHSTRING)
  ext = generateExternalSymbols(symbols)
  return "{}{}\n\n{}{}".format(sp[0], SEARCHSTRING, ext, sp[1])

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
  s = "\n".join(defines)
  with open("example/test_def.h", "w") as f:
    f.write(s)
  return defineIdx

def main():
  s = ""
  with open("example/test.c", "r") as f:
    s = f.read()
  n = insertExternalSymbols(s)

  ls = n.split("\n")
  defineIdx = createHeaderFile(ls)

  out = "#ifndef __TEST_EXT__\n#define __TEST_EXT__\n\n{}\n#endif".format(
    "\n".join(["#include \"test_def.h\""] + ls[defineIdx:]))

  with open("example/test_ext.h", "w") as f:
    f.write(out)

if __name__ == "__main__":
  main()

