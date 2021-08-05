import argparse
import fileinput
import re

def fixup_pb(pb_header):
  print(f"FIX: {pb_header}")
  for line in fileinput.input(pb_header, inplace=True):
    if not re.match(r"^\s*typedef .*Service;", line):
      print(line, end='')
    else:
      print(f"// {line}")

if __name__ == "__main__":
  parser = argparse.ArgumentParser(description = "Fixup pb files for nested template issues.")
  parser.add_argument("pbh", help = "Path to the pb.h file to fixup.")
  args = parser.parse_args()
  fixup_pb(args.pbh)