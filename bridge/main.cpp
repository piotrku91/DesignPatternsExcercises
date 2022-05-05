
#include <iostream>
#include "motordriver.hpp"

int main() {
    const MotorDriverAPISoft soft_motor_api;
    const MotorDriverAPIRaw normal_motor_api;

    FrontMotor motor1{50, 1, soft_motor_api};
    FrontMotor motor2{50, 1, normal_motor_api};
    
    motor1.IncSpeed();
    motor1.IncSpeed();
    motor1.ChangeDirection();
    std::cout << motor1.Drive() << std::endl;
    std::cout << motor2.Drive() << std::endl;
}
