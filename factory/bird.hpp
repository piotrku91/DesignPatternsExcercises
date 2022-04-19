#pragma once
#include <string>
#include <memory>

class Bird {
protected:
    std::string name_;

public:
    virtual ~Bird() = default;
    virtual void setName(const std::string& new_bird_name) = 0;
    std::string getName() const { return name_; };
};

struct BirdFactory {
    virtual std::shared_ptr<Bird> make() const = 0;

    template <typename T>
    static std::shared_ptr<Bird> make() {return std::make_shared<T>();}
};

struct Eagle : public Bird {
    void setName(const std::string& new_bird_name) override {name_ ="EAGLE: "+ new_bird_name;};
};

struct Flaming : public Bird {
    void setName(const std::string& new_bird_name) override {name_ ="FLAMING: "+  new_bird_name;};
};

struct EagleFactory : public BirdFactory {
     std::shared_ptr<Bird> make() const override {
        return std::make_shared<Eagle>();
    };
};

struct FlamingFactory : public BirdFactory {
      std::shared_ptr<Bird> make() const override {
        return std::make_shared<Flaming>();
    };
};

