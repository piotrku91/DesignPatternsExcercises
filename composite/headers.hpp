#pragma once
#include <iostream>
#include <string>
#include <vector>

class Marker {
public:
    virtual std::string get() = 0;
};

class DoubleMarker : public Marker {
private:
    std::string chars_;

public:
    DoubleMarker(const std::string& double_char_marker)
        : chars_(double_char_marker){};
    std::string get() override {
        return chars_.substr(0, 2);
    }
};

class MarkerGroup : public Marker {
public:
    std::string name_;
    std::vector<Marker*> items_;

    MarkerGroup(const std::string& name)
        : name_(name){};

    std::string get() override {
        std::string temp_string = "  " + name_ + " contains: \n";

        for (auto&& item : items_) {
            temp_string += item->get() + "\n";
        }
        return temp_string;
    }

    std::vector<Marker*>::iterator begin() {
        return items_.begin();
    }

    std::vector<Marker*>::iterator end() {
        return items_.end();
    }
};