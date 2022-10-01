//
// Created by barhamm on 9/30/22.
//

#ifndef BLACKJACK_CPP_HAND_H
#define BLACKJACK_CPP_HAND_H


#include <vector>
#include "Card.h"

class Hand {
public:
    void add_card(Card card);
    void adjust_for_aces();

    std::vector<Card> get_cards() const { return _cards; }
    int get_value() const { return _value; }

private:
    std::vector<Card> _cards;
    int _value{};
    int _aces{};

};


#endif //BLACKJACK_CPP_HAND_H
