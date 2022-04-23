
#include <iostream>
#include <memory>
#include <set>
#include "cube.hpp"
#include "mainpointsdisplay.hpp"

class VectorShapeCubeToMainPointsDisplayAdapter {
private:
    std::vector<Point> checked_main_points;

public:
    std::vector<Point> convert(std::shared_ptr<VectorShapeObject> cube) {
        std::vector<Point> processed_points;
        checked_main_points.clear();

        for (auto& line : *cube) {
            Point proc_point = {line.Start_.x, line.Start_.y, line.Start_.z};
            processed_points.emplace_back(proc_point);
            if (std::find(processed_points.begin(), processed_points.end(), proc_point) != processed_points.end()) {
                if (std::find(checked_main_points.begin(), checked_main_points.end(), proc_point) == checked_main_points.end()) {
                    checked_main_points.push_back(proc_point);
                }
            }
            proc_point = {line.End_.x, line.End_.y, line.End_.z};
            processed_points.emplace_back(proc_point);
            if (std::find(processed_points.begin(), processed_points.end(), proc_point) != processed_points.end()) {
                if (std::find(checked_main_points.begin(), checked_main_points.end(), proc_point) == checked_main_points.end()) {
                    checked_main_points.push_back(proc_point);
                }
            }
        }
        return checked_main_points;
    }
};

int main() {
    std::shared_ptr<VectorShapeObject> shapes = std::make_shared<VectorShapeCube>(0, 0, 0, 10);

    for (auto& line : *shapes) {
        std::cout << "Line start at point -> " << line.Start_.x << ", " << line.Start_.y << ", " << line.Start_.z << " | "
                                                                                                                     "Line stop at point -> "
                  << line.End_.x << ", " << line.End_.y << ", " << line.End_.z << " | " << std::endl;
    }

    MainPointsDisplay main_points_display;

    // main_points_display.setMainPoints();
    // Is incopatible with cube, because cube interface return all points (begin and end of lines)
    // so adapter should help

    VectorShapeCubeToMainPointsDisplayAdapter cube_to_main_points_adapter;

    main_points_display.setMainPoints(cube_to_main_points_adapter.convert(shapes));
    main_points_display.showMainPoints();
}
