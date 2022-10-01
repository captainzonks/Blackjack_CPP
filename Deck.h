//
// Created by barhamm on 9/30/22.
//

#ifndef BLACKJACK_CPP_DECK_H
#define BLACKJACK_CPP_DECK_H

#include <vector>

#include "Card.h"

class Deck {
public:
    Deck();

    void shuffle();

    Card deal();

    void print_cards();
private:
    std::vector<Card> _cards{};
};


#endif //BLACKJACK_CPP_DECK_H
