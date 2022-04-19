
#include <iostream>
#include "square.hpp"
#include "bird.hpp"

int main() 
{
auto squareNormal = Square::newNormalSquare(50, 50);
auto squareDoubled = Square::newDoubledSquare(50, 50);
auto squareScaled = Square::newScaledSquare(50, 50, 100);

std::cout << squareNormal << std::endl;
std::cout << squareDoubled << std::endl;
std::cout << squareScaled << std::endl;

EagleFactory eagle_factory;
FlamingFactory flaming_factory;

auto bird1 = eagle_factory.make();
bird1->setName("Destroyer");

auto bird2 = flaming_factory.make();
bird2->setName("Pink friend");

auto bird3 = BirdFactory::make<Eagle>();
bird3->setName("Banger");


std::cout << bird1->getName() << std::endl;
std::cout << bird2->getName() << std::endl;
std::cout << bird3->getName() << std::endl;


}
