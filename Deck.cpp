//
// Created by barhamm on 9/30/22.
//

#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include "Deck.h"

Deck::Deck() {

    for (int suitInt{ static_cast<int>(SUIT::Hearts) }; static_cast<SUIT>(suitInt) != SUIT::NONE; suitInt++) {
        for (int rankInt{ static_cast<int>(RANK::One) }; static_cast<RANK>(rankInt) != RANK::NONE; rankInt++) {
            Card card(static_cast<SUIT>(suitInt), static_cast<RANK>(rankInt));
            this->_cards.push_back(card);
        }
    }

}

void Deck::print_cards() {

    for (Card card: _cards) {
        std::cout << card << std::endl;
    }

}

void Deck::shuffle() {
    unsigned seed{ static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count()) };
    auto rng{ std::default_random_engine{ seed }};
    std::shuffle(_cards.begin(), _cards.end(), rng);
}

Card Deck::deal() {
    Card back_card{ this->_cards.back() };
    this->_cards.pop_back();
    return back_card;
}
