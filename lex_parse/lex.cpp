#include "lex.hpp"

std::vector<Token> lex(const std::string input_string) {
    std::vector<Token> new_tokens;

    for (size_t i = 0; i < input_string.size(); i++)
        switch (input_string[i]) {
        case '+': {
            new_tokens.push_back(Token(input_string[i], TokenType::Addition));
            break;
        }
        case '-': {
            new_tokens.push_back(Token(input_string[i], TokenType::Subtract));
            break;
        }
        case '(': {
            new_tokens.push_back(Token(input_string[i], TokenType::LeftParenthesis));
            break;
        }
        case ')': {
            new_tokens.push_back(Token(input_string[i], TokenType::RightParenthesis));
            break;
        }
        default: {
            std::string int_output{""};
            int_output += input_string[i];

            for (size_t j = i + 1; j < input_string.size(); j++) {
                if (isdigit(input_string[j]))  // if next char is digit
                {
                    int_output += input_string[j];
                    ++i;
                } else {
                    new_tokens.push_back(Token(int_output, TokenType::Integer));  // Integer collected
                    break;
                }
            }
        };
        }
    return new_tokens;
}