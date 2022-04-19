
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "HtmlBuilder.hpp"

int main() {
    HtmlBuilder builder{"ul"};
    builder.add_child("li", "hello").add_child("li", "world").add_child("li", "world");

    std::cout << builder.str() << std::endl;
  


}
