#include <iostream>
#include "lex.hpp"

int main() 
{
auto collected_tokens = lex("(2+2)-(1+1)");

for (auto&& t : collected_tokens)
{
std::cout << " " << t.getText() << " ";
}
std::cout << "\n";

}
