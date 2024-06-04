import argparse
import sys
import json
import enum

# ?  IMPORT LEXER CODE PARTS
from error import Error, IllegalCharError
from position import Position
from tokentypes import DIGITS, TokenType
from token import Token

class Lexer:
    def __init__(self, fn, text):
        self.fn = fn
        self.text = text
        self.pos = Position(-1, 0, -1, fn, text)
        self.current_char = None

        self.advance()

    def advance(self):
        self.pos.advance(self.current_char)
        self.current_char = self.text[self.pos.idx] if self.pos.idx < len(self.text) else None

    def make_number(self):
        num_str = ''
        dot_count = 0

        while self.current_char is not None and self.current_char in DIGITS + '.':
            if self.current_char == '.':
                if dot_count > 0:
                    break

                dot_count = 1
                num_str += '.'
            else:
                num_str += self.current_char
            self.advance()

        if not dot_count:
            return Token(TokenType.TT_INT, int(num_str))
        else:
            return Token(TokenType.TT_FLOAT, float(num_str))

    def make_word(self):
        word = ''

        while self.current_char is not None and 'a' <= self.current_char <= 'z':
            word += self.current_char

            self.advance()

        if word == 'main':
            return Token(TokenType.TT_MAIN, None)
        elif word == 'add':
            return Token(TokenType.TT_ADD, None)
        elif word == 'ret':
            return Token(TokenType.TT_RET, None)
        else:
            return Token(TokenType.TT_VAR, word)

    def make_tokens(self):
        tokens = []

        while self.current_char is not None:
            if self.current_char in ' \t\n':
                self.advance()
            elif self.current_char in DIGITS:
                tokens.append(self.make_number())
            elif 'z' >= self.current_char >= 'a':
                tokens.append(self.make_word())
            elif self.current_char == ':':
                tokens.append(Token(TokenType.TT_COLON, None))
                self.advance()
            elif self.current_char == "=":
                tokens.append(Token(TokenType.TT_EQUAL, None))
                self.advance()
            elif self.current_char == ",":
                tokens.append(Token(TokenType.TT_COMA, None))
                self.advance()
            else:
                # ?  return errors
                pos_start = self.pos.copy()
                char = self.current_char
                self.advance()

                return [], IllegalCharError(pos_start, self.pos, "'" + char + "'")

        return tokens, None


def main():
    parser = argparse.ArgumentParser(description="Lexer")
    parser.add_argument("--file", required=True, help="*.my")

    args = parser.parse_args()

    file_name = args.file
    text = ''
    fn = '<stdin>'

    with open(file_name, mode="r", encoding="utf-8") as file:
        text = file.read()

    lexer = Lexer(fn, text)
    tokens, error = lexer.make_tokens()

    if error:
        print(error.error2str())
        return
    
    print(tokens)

if __name__ == '__main__':
    main()
