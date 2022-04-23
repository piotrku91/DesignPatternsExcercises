#pragma once

#include <vector>

struct Point3 {
    int x;
    int y;
    int z;
};

struct Line {
    Point3 Start_;
    Point3 End_;
};

struct VectorShapeObject {
    virtual std::vector<Line>::iterator begin() = 0;
    virtual std::vector<Line>::iterator end() = 0;
};

class VectorShapeCube : public VectorShapeObject {
    std::vector<Line>::iterator begin() override { return RawLines_.begin(); };
    std::vector<Line>::iterator end() override { return RawLines_.end(); };

public:
    VectorShapeCube(int x, int y, int z, int length, int visualshift = 5) {
        //Bottom
        RawLines_.emplace_back(Point3{x, y, z}, Point3{x + length, y, z});
        RawLines_.emplace_back(Point3{x + length, y, z}, Point3{x + length + visualshift, y + length, z});
        RawLines_.emplace_back(Point3{x + length + visualshift, y + length, z}, Point3{x + visualshift, y + length, z});
        RawLines_.emplace_back(Point3{x + visualshift, y + length, z}, Point3{x, y, z});

        //Between
        RawLines_.emplace_back(Point3{x, y, z}, Point3{x, y, z + length});
        RawLines_.emplace_back(Point3{x + length, y, z}, Point3{x + length, y, z + length});
        RawLines_.emplace_back(Point3{x + length + visualshift, y + length, z}, Point3{x + length + visualshift, y + length, z + length});
        RawLines_.emplace_back(Point3{x + visualshift, y + length, z}, Point3{x + visualshift, y + length, z + length});

        //Up
        RawLines_.emplace_back(Point3{x, y, z + length}, Point3{x + length, y, z + length});
        RawLines_.emplace_back(Point3{x + length, y, z + length}, Point3{x + length + visualshift, y + length, z + length});
        RawLines_.emplace_back(Point3{x + length + visualshift, y + length, z + length}, Point3{x + visualshift, y + length, z + length});
        RawLines_.emplace_back(Point3{x + visualshift, y + length, z + length}, Point3{x, y, z + length});
    }

private:
    std::vector<Line> RawLines_;
};
