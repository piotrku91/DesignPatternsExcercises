#pragma once
#include <iostream>
#include <stddef.h>

class Square {
    size_t width_;
    size_t height_;

    Square(size_t width, size_t height)
        : width_(width), height_(height){};

public:
    size_t getWidth() const {return width_;};
    size_t getHeight() const {return height_;};
    
    static Square newNormalSquare(size_t width, size_t height) {return Square{width, height};};
    static Square newDoubledSquare(size_t width, size_t height) {return Square{2*width, 2*height};};
    static Square newScaledSquare(size_t width, size_t height, size_t scale = 1) {return Square{scale*width, scale*height};};

    friend std::ostream &operator<<(std::ostream &oss, const Square& square)
    {
        oss << "SQUARE - " << "w:" << square.getWidth() << " h:" << square.getHeight();
        return oss;
    };
};