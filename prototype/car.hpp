#pragma once
#include <string>
#include <memory>


class CarDetails
{
public:
std::string company_;
std::string color_;
std::string engine_;
size_t max_speed_;

public:
CarDetails(const std::string& company, const std::string& color, const std::string& engine, size_t max_speed): 
            company_(company), color_(color), engine_(engine), max_speed_(max_speed) {};
CarDetails() = delete;

};

class Car
{
private:
std::string name_;
std::shared_ptr<CarDetails> details_;

public:
std::string getName() const {return name_;};
std::shared_ptr<CarDetails> getDetails() const {return details_;};
std::shared_ptr<CarDetails> setDetails() {return details_;};

Car(const std::string& name, const std::string& company, const std::string& color, const std::string& engine, size_t max_speed):
    name_(name), details_(std::make_shared<CarDetails>(company, color, engine, max_speed)) {};

Car(const std::string& name, const Car& other):name_(name), details_(std::make_shared<CarDetails>(other.details_->company_, other.details_->color_, other.details_->engine_, other.details_->max_speed_)){}
Car(const Car& other):name_(other.name_), details_(std::make_shared<CarDetails>(other.details_->company_, other.details_->color_, other.details_->engine_, other.details_->max_speed_)){}
};