
#include <iostream>
#include "device.hpp"

int main() {
    Device a;

    std::cout << a.power << std::endl;
    a.power = 50;
    std::cout << a.power << std::endl;
}
