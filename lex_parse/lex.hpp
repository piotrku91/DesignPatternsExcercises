#pragma once
#include <iostream>
#include <vector>

enum class TokenType
{
    Integer,
    Addition,
    Subtract,
    LeftParenthesis,
    RightParenthesis
};

class Token
{

private:
    std::string text_;
    TokenType token_type_;

public:
    Token(const std::string& text, TokenType token_type):text_{text}, token_type_{token_type} {};
    Token(const char text, TokenType token_type):text_{text}, token_type_{token_type} {};

    std::string getText() const {return text_;};
    TokenType getType() const {return token_type_;};
};

std::vector<Token> lex(const std::string input_string);