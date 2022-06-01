#pragma once
#include <map>
#include <string>

using IndexKey = int;

class User {
private:
    IndexKey name_;
    IndexKey lastname_;

public:
    User(const std::string& name, const std::string& lastname)
        : name_{add(name)}, lastname_{add(lastname)} {};

    std::string getName() const {
        return mapper[name_];
    }

    IndexKey getIndexOfName() const {
        return name_;
    }

    std::string getLastName() const {
        return mapper[lastname_];
    }

    IndexKey getIndexOfLastname() const {
        return lastname_;
    }

    static std::map<int, std::string> mapper;
    static IndexKey current;
    static IndexKey add(const std::string& name) {
        for (auto& [key, value] : mapper) {
            if (value == name) {
                return key;
            };
        }
        mapper.insert({++current, name});
        return current;
    }
};

IndexKey User::current = 0;
std::map<int, std::string> User::mapper = {};