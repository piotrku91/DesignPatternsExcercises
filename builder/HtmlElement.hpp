#pragma once

#include "HtmlBuilder.hpp"

struct HtmlBuilder;

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct HtmlElement {
    friend class HtmlBuilder;
private:
    HtmlElement(){};
    HtmlElement(const std::string& name, const std::string& text)
        : name(name), text(text){};

public:
    std::string name;
    std::string text;
    std::vector<HtmlElement> elements;
    const size_t indent_size = 2;
    const char indent_char = ' ';

    std::string str(int indent = 0) {
        std::ostringstream oss;

        std::string i(indent_size * indent, indent_char);
        oss << i << "<" << name << ">" << std::endl;
        if (text.size() > 0) {
            oss << std::string(indent_size * (indent + 1), indent_char) << text << std::endl;
        };

        for (auto& e : elements) {
            oss << e.str(indent + 1) << std::endl;
        }

        oss << i << "</" << name << ">" << std::endl;
        return oss.str();
    };
};