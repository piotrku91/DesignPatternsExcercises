#pragma once
#include <iomanip>
#include <string>
#include <vector>

class ConsoleTableMaker {
    ConsoleTableMaker(){};

public:
    static ConsoleTableMaker& get() {
        static ConsoleTableMaker hm;
        return hm;
    };

    std::string getHeader(const std::string& text, char line_char, int table_size = 80) {
        std::stringstream oss;

        oss << std::setw(table_size) << std::setfill(line_char) << "\n"
            << std::setfill(' ')
            << line_char
            << std::setw(table_size - 2)
            << line_char << "\n"
            << std::setw(table_size) << std::setfill(line_char) << "\n";

        std::string return_string = oss.str();
        return return_string.replace(((table_size) + ((table_size / 2) - 1) - (text.length() / 2)), text.length(), text);
    };

    std::string getEntries(std::vector<std::string> entries, char line_char, int table_size = 80) {
        std::stringstream oss;

        int counter = 1;
        for (const auto& entry : entries) {
            oss << line_char
                << " "
                << counter++
                << ". "
                << entry
                << std::setw(table_size - static_cast<int>(entry.length()) - 6) << line_char
                << "\n";
        };
        return oss.str();
    };

    std::string getFooter(char line_char, int table_size = 80) {
        std::stringstream oss;
        oss << std::setw(table_size) << std::setfill(line_char) << "\n";

        return oss.str();
    };
};