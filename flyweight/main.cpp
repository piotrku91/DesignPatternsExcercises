
#include <iostream>
#include "user.hpp"

int main() 
{
    User user1{"Piotr", "Wojak"};
    User user2{"Piotr", "Rotunda"};
    User user3{"Piotr", "Cikler"};
    User user4{"Jurek", "Wojak"};


std::cout << user1.getName() << " " << user1.getLastName() << "| Name index: " << user1.getIndexOfName() << "| lastName index: " << user1.getIndexOfLastname() << std::endl;
std::cout << user2.getName() << " " << user2.getLastName() << "| Name index: " << user2.getIndexOfName() << "| lastName index: " << user2.getIndexOfLastname() << std::endl;
std::cout << user3.getName() << " " << user3.getLastName() << "| Name index: " << user3.getIndexOfName() << "| lastName index: " << user3.getIndexOfLastname() << std::endl;
std::cout << user4.getName() << " " << user4.getLastName() << "| Name index: " << user4.getIndexOfName() << "| lastName index: " << user4.getIndexOfLastname() << std::endl;
}
