#pragma once
#include <string>

class MotorDriverAPI {
public:
    virtual ~MotorDriverAPI() = default;
    virtual std::string Drive(int pwm, int direction) const = 0;
};

class MotorDriverAPISoft : public MotorDriverAPI {
public:
    std::string Drive(int pwm, int direction) const override { return "Drive slow 3, 2, 1 \n Then drive " + std::to_string(pwm) + " PWM and Direction " + std::to_string(direction); };
};

class MotorDriverAPIRaw : public MotorDriverAPI {
public:
    std::string Drive(int pwm, int direction) const override { return "Drive max " + std::to_string(pwm) + " PWM and Direction " + std::to_string(direction); };
};

class Motor {
public:
    Motor(const MotorDriverAPI& motor_driver_api)
        : motor_driver_api_(motor_driver_api){};
    virtual ~Motor() = default;

    virtual std::string Drive() const = 0;
    virtual void ChangeDirection() = 0;
    virtual void IncSpeed() = 0;

protected:
    const MotorDriverAPI& motor_driver_api_;
};

class FrontMotor : public Motor {
public:
    FrontMotor(int pwm, int direction, const MotorDriverAPI& motor_driver_api)
        : Motor(motor_driver_api), pwm_(pwm), direction_(direction){};

    std::string Drive() const override {
        return motor_driver_api_.Drive(pwm_, direction_);
    };

    void ChangeDirection() override {
        direction_ = -direction_;
    };

    void IncSpeed() override {
        pwm_++;
    };

private:
    int pwm_;
    int direction_;
};
