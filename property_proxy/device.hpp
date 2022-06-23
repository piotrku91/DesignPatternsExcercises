#pragma once

template <typename T>
class Property {
    T value;

public:
    Property(T value) {
        *this = value;
    };

    operator T() {
        return value;
    }

    T operator=(T new_value) {
        value = new_value;
        return value;
    };
};

class Device {
public:
    Property<int> power{20};
    Property<bool> state{false};
};