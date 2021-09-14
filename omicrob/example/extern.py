
from typing import List

SEARCHSTRING = "#include </home/ben/omicrob/src/byterun/vm/runtime.c>"

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

def main():
  s = ""
  with open("example/test.c", "r") as f:
    s = f.read()
  n = insertExternalSymbols(s)
  with open("example/test_ext.c", "w") as f:
    f.write(n)

if __name__ == "__main__":
  main()

