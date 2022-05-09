
#include <iostream>
#include "headers.hpp"

int main() {
    DoubleMarker open(">>");
    DoubleMarker inside("**");
    DoubleMarker close("<<>>>>");

    MarkerGroup markers("First level");
    MarkerGroup markers_nested("Second level");

    markers_nested.items_.push_back(&open);
    markers_nested.items_.push_back(&inside);
    markers_nested.items_.push_back(&inside);
    markers_nested.items_.push_back(&inside);
    markers_nested.items_.push_back(&close);

    markers.items_.push_back(&open);
    markers.items_.push_back(&inside);
    markers.items_.push_back(&markers_nested);
    markers.items_.push_back(&inside);
    markers.items_.push_back(&close);

    std::cout << markers.get() << std::endl;

    std::cout << "---------------------------------\n";

    for (auto&& mark_ext : markers) {
        std::cout << mark_ext->get() << "\n";
    }
}
