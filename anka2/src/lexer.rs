use strum_macros::Display;

#[derive(Display, Debug)]
pub enum TokenType {
    Word,
    TupleStart,
    Number,
    TupleEnd,
}

pub struct Token<'a> {
    pub token_type: TokenType,
    pub value: &'a str, // use a string slice
}

fn iterate_until(
    iter: &mut std::iter::Peekable<std::iter::Enumerate<std::str::Chars>>,
    condition: fn(char) -> bool,
) -> usize {
    let mut len: usize = 1;

    while let Some((_index, next)) = iter.peek() {
        if !condition(*next) {
            break;
        }
        len = len + 1;
        iter.next();
    }

    return len;
}

fn is_name_char(c: char) -> bool {
    return c.is_ascii_alphabetic() || c.is_ascii_digit() || c == '_';
}

pub fn lex(contents: &str) -> Vec<Token> {
    let mut tokens: Vec<Token> = Vec::new();

    let mut iter = contents.chars().enumerate().peekable();

    while let Some((index, next)) = iter.next() {
        match next {
            '[' => tokens.push(Token {
                token_type: TokenType::TupleStart,
                value: "[",
            }),
            ']' => tokens.push(Token {
                token_type: TokenType::TupleEnd,
                value: "]",
            }),
            '0'..='9' => {
                let len = iterate_until(&mut iter, |c| c.is_ascii_digit());
                tokens.push(Token {
                    token_type: TokenType::Number,
                    value: &contents[index..index + len],
                });
            }
            ' ' | '\n' => {
                // ignore whitespace
            }
            _ => {
                if is_name_char(next) {
                    let len = iterate_until(&mut iter, |c| is_name_char(c));
                    tokens.push(Token {
                        token_type: TokenType::Word,
                        value: &contents[index..index + len],
                    });
                }
            }
        }
    }

    return tokens;
}
