#pragma once
#include <memory>

struct Card {
    int attack_power_;
    bool can_be_blocked_;
    int points_;

    Card(int attack_power, bool can_be_blocked, int points)
        : attack_power_{attack_power}, can_be_blocked_{can_be_blocked}, points_{points} {};
};

class CardModifier {
public:
    std::shared_ptr<CardModifier> next_;
    CardModifier(Card& card)
        : next_{nullptr}, card_{card} {};

protected:
    Card& card_;

public:

    void addToChain(std::shared_ptr<CardModifier> modifier) {
        if (next_) {
            next_->addToChain(modifier);
        } else {
            next_ = modifier;
        };
    }

    virtual void perform() {
        if (next_) {
            next_->perform();
        };
    };
};

class AttackPowerIncrementModifier : public CardModifier
{
    public:
    AttackPowerIncrementModifier(Card& card): CardModifier(card){};

void perform() override {
      card_.attack_power_++;
      CardModifier::perform();
    };

};

class NoBlockModifier : public CardModifier
{
    public:
    NoBlockModifier(Card& card): CardModifier(card){};

void perform() override {
      card_.can_be_blocked_ = false;
      CardModifier::perform();
    };

};

class PointsReductionModifier : public CardModifier
{
    public:
    PointsReductionModifier(Card& card): CardModifier(card){};

void perform() override {
      card_.points_--;
      CardModifier::perform();
    };

};