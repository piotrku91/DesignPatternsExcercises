#pragma once
#include <iostream>
#include <vector>

struct Point {
    int x;
    int y;
    int z;

    bool operator==(const Point& other) const {
        return ((this->x == other.x) && (this->y == other.y) && (this->z == other.z));
    }
};

class MainPointsDisplay {
    std::vector<Point> MainPoints_;

public:
    void setMainPoints(std::vector<Point> main_points) { MainPoints_ = std::move(main_points); };

    void showMainPoints() {
        for (auto& point : MainPoints_) {
            std::cout << "MainPoint: " << point.x << ", " << point.y << ", " << point.z << "\n";
        }
    };
};