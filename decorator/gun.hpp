#pragma once
#include <functional>
#include <string>
#include <vector>

class Gun {
protected:
    int ammo_;
    int power_;

public:
    virtual std::string getName() = 0;
    virtual std::string getPowerString() = 0;
    virtual int getPower() { return power_; };
};

class Colt : public Gun {
public:
    Colt(int init_ammo, int power) {
        ammo_ = init_ammo;
        power_ = power;
    };
    std::string getName() override { return "Colt with ammo " + std::to_string(ammo_); };
    std::string getPowerString() override { return "Power of Colt = " + std::to_string(power_); };
};

class Modifier {
private:
    std::string tool_name_;
    std::function<int(int)> power_modifier_function_;

public:
    Modifier(std::string tool_name, std::function<int(int)> power_modifier_function)
        : tool_name_(tool_name), power_modifier_function_(power_modifier_function){};

    std::string getToolName() const { return tool_name_; };
    int getModifiedPower(int input) {
        if (power_modifier_function_) {
            return power_modifier_function_(input);
        };
        return input;
    };
};

class GunWithModifier : public Gun {
private:
    Gun& gun_;
    Modifier& modifier_;

public:
    GunWithModifier(Gun& gun_to_mod, Modifier& gun_modifier)
        : gun_(gun_to_mod), modifier_(gun_modifier){};

    std::string getName() override { return gun_.getName() + " (with " + modifier_.getToolName() + ")"; };
    std::string getPowerString() override { return gun_.getPower() + " (with " + std::to_string(modifier_.getModifiedPower(gun_.getPower())) + ")"; };
    int getPower() override { return modifier_.getModifiedPower(gun_.getPower()); };
};