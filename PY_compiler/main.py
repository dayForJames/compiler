import argparse
import sys
import json
import enum

from lexer import Lexer

def main():
    parser = argparse.ArgumentParser(description="Lexer")
    parser.add_argument("--file", required=True, help="*.my")

    args = parser.parse_args()

    file_name = args.file
    text = ""
    fn = "<stdin>"

    with open(file_name, mode="r", encoding="utf-8") as file:
        text = file.read()

    lexer = Lexer(fn, text)
    tokens, error = lexer.make_tokens()

    if error:
        print(error.error2str())
        return

    print(tokens)


if __name__ == "__main__":
    main()
