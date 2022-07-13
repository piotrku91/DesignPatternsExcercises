
#include <iostream>
#include "card.hpp"
#include <memory>

int main() 
{

Card battle_card1(8, false, 3);

std::cout << "| Attack power: " << battle_card1.attack_power_ <<
 " | Can be blocked: " << battle_card1.can_be_blocked_ << " | Points: " << battle_card1.points_ << std::endl;

CardModifier root_mod{battle_card1};

auto att_mod = std::make_shared<AttackPowerIncrementModifier>(battle_card1);
auto noblck_mod = std::make_shared<NoBlockModifier>(battle_card1);
auto ptsred_mod = std::make_shared<PointsReductionModifier>(battle_card1);

root_mod.addToChain(att_mod);
root_mod.addToChain(noblck_mod);
root_mod.addToChain(ptsred_mod);


root_mod.perform();

std::cout << "| Attack power: " << battle_card1.attack_power_ <<
 " | Can be blocked: " << battle_card1.can_be_blocked_ << " | Points: " << battle_card1.points_ << std::endl;

}
