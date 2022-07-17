
#include <iostream>
#include "object.hpp"
#include <vector>

int main() 
{
Object cube{{0, 0, 0}};

std::cout << cube.getPosition().posX_<< " | " << cube.getPosition().posY_<< " | " << cube.getPosition().posZ_<< " | " << std::endl;

std::vector<ObjectCommand> commands = 
{
    ObjectCommand{cube, CommandType::setPosition, {10, 10, 10}},
    ObjectCommand{cube, CommandType::shiftPosition, {50, 50, 50}}
};

for (auto& cmd: commands)
{
    cmd.call();
}

std::cout << cube.getPosition().posX_<< " | " << cube.getPosition().posY_<< " | " << cube.getPosition().posZ_<< " | " << std::endl;

}
