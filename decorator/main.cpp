
#include <functional>
#include <iostream>
#include "gun.hpp"

int main() {
    Colt default_colt(25, 100);
    Modifier silencer_doubled_power("silencer", [](auto input) { return input * 2; });
    Modifier fast_reloader("fast reloader", [](auto input) { return input * 5000; });

    GunWithModifier silenced_colt(default_colt, silencer_doubled_power);
    std::cout << default_colt.getName() << " | " << default_colt.getPower() << std::endl;
    std::cout << silenced_colt.getName() << " | " << silenced_colt.getPower() << std::endl;

    GunWithModifier fast_reloading_colt(default_colt, fast_reloader);
    std::cout << default_colt.getName() << " | " << default_colt.getPower() << std::endl;
    std::cout << fast_reloading_colt.getName() << " | " << fast_reloading_colt.getPower() << std::endl;
}
