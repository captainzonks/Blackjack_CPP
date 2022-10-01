//
// Created by barhamm on 9/30/22.
//

#include "Hand.h"

void Hand::add_card(Card card) {
    this->_cards.push_back(card);
    this->_value += card.get_value();
    if (card.get_rank() == RANK::Ace) {
        this->_aces += 1;
    }
}

void Hand::adjust_for_aces() {
    if (this->_value > 21 && this->_aces > 0) {
        this->_value -= 10;
        this->_aces -= 1;
    }
}
