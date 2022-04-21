
#include <iostream>
#include <vector>
#include "car.hpp"

int main() {
    Car basic_car_template("VB000", "NONAME", "RED", "PETROL", 150);
    Car fast_car_template("VF000", "NONAME", "BLUE", "GASOLINE", 200);

    std::vector<Car> basic_cars;
    std::vector<Car> fast_cars;

    basic_cars.emplace_back("VOO1", basic_car_template);
    basic_cars[0].setDetails()->color_ = "PINK";
    basic_cars.emplace_back("VOO2", basic_car_template);
    basic_cars.emplace_back("VOO3", basic_car_template);
    basic_cars.emplace_back("VOO4", basic_car_template);

    fast_cars.emplace_back("VF001", fast_car_template);
    fast_cars[0].setDetails()->color_ = "GRAY";
    fast_cars.emplace_back("VF002", fast_car_template);
    fast_cars.emplace_back("VF003", fast_car_template);
    fast_cars.emplace_back("VF004", fast_car_template);

    Car new_car = Car{basic_cars[0]};
    Car new_car2 = basic_cars[0];

    basic_cars.push_back(new_car);
    basic_cars.push_back(new_car2);

    auto printCars = [](const auto& cars_to_show) {
        for (const auto& car : cars_to_show) {
            std::cout << car.getName() << " - " << car.getDetails()->company_ << " | "
                      << car.getDetails()->color_ << " | "
                      << car.getDetails()->engine_ << " | "
                      << car.getDetails()->max_speed_ << " | " << std::endl;
        };
    };

    printCars(basic_cars);
    printCars(fast_cars);

}
