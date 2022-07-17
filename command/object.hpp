#pragma once
#include <iostream>

struct Coords
{
    size_t posX_;
    size_t posY_;
    size_t posZ_;
};

class Object
{
    private:
    Coords position_;

    public:
    void setPosition(Coords new_position)
    {
        position_ = new_position;
    };

    void shiftPosition(Coords shift_by_position)
    {
        position_.posX_ += shift_by_position.posX_;
        position_.posY_ += shift_by_position.posX_;
        position_.posZ_ += shift_by_position.posY_;
    };

    Coords getPosition() const
    {
        return position_;
    }

    Object(Coords init_position):position_(init_position) {};
};

class Command
{
    public:
    virtual void call() = 0;
};

enum CommandType
{
    setPosition,
    shiftPosition
};

class ObjectCommand : public Command
{
    private:
    Object& object_;
    CommandType commandType_;
    Coords position_to_action_;

    public:
    ObjectCommand(Object& object, CommandType command_type, Coords position_to_action):object_(object), 
    commandType_(command_type), position_to_action_(position_to_action) {};

    void call() override {
        switch (commandType_)
        {
            case setPosition:
            {
                object_.setPosition(position_to_action_);
                break;
            }
            case shiftPosition:
            {
                object_.shiftPosition(position_to_action_);
                break;
            }
            default:
            {

            }
        }
    }

};