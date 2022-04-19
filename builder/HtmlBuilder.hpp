#pragma once

#include "HtmlElement.hpp"

struct HtmlBuilder {
    HtmlElement root;

    HtmlBuilder(std::string root_name) {
        root.name = root_name;
    }

    HtmlBuilder& add_child(std::string child_name, std::string child_text) {
        HtmlElement e{child_name, child_text};
        root.elements.emplace_back(e);
        return *this;
    };


    std::string str() { return root.str(); };

   static HtmlBuilder build(std::string root_name) {
        return {root_name};
    }

    operator HtmlElement()
    {
        return root;;
    }
    
};