//
// Created by barhamm on 9/30/22.
//

#include "Card.h"

Card::Card(SUIT suit, RANK rank) : _suit(suit), _rank(rank) {
    set_value();
}

void Card::set_value() {
    switch (this->_rank) {
        case RANK::One:
            this->_value = 1;
            break;
        case RANK::Two:
            this->_value = 2;
            break;
        case RANK::Three:
            this->_value = 3;
            break;
        case RANK::Four:
            this->_value = 4;
            break;
        case RANK::Five:
            this->_value = 5;
            break;
        case RANK::Six:
            this->_value = 6;
            break;
        case RANK::Seven:
            this->_value = 7;
            break;
        case RANK::Eight:
            this->_value = 8;
            break;
        case RANK::Nine:
            this->_value = 9;
            break;
        case RANK::Ten:
            this->_value = 10;
            break;
        case RANK::Jack:
            this->_value = 10;
            break;
        case RANK::Queen:
            this->_value = 10;
            break;
        case RANK::King:
            this->_value = 10;
            break;
        case RANK::Ace:
            this->_value = 11;
            break;
        case RANK::NONE:
            this->_value = 0;
            break;
    }
}

std::ostream& operator<<(std::ostream& stream, const Card& card) {

    std::string card_rank{};
    std::string card_suit{};

    switch (card._rank) {

        case RANK::One:
            card_rank = "One";
            break;
        case RANK::Two:
            card_rank = "Two";
            break;
        case RANK::Three:
            card_rank = "Three";
            break;
        case RANK::Four:
            card_rank = "Four";
            break;
        case RANK::Five:
            card_rank = "Five";
            break;
        case RANK::Six:
            card_rank = "Six";
            break;
        case RANK::Seven:
            card_rank = "Seven";
            break;
        case RANK::Eight:
            card_rank = "Eight";
            break;
        case RANK::Nine:
            card_rank = "Nine";
            break;
        case RANK::Ten:
            card_rank = "Ten";
            break;
        case RANK::Jack:
            card_rank = "Jack";
            break;
        case RANK::Queen:
            card_rank = "Queen";
            break;
        case RANK::King:
            card_rank = "King";
            break;
        case RANK::Ace:
            card_rank = "Ace";
            break;
        case RANK::NONE:
            card_rank = "None";
            break;
    }

    switch (card._suit) {
        case SUIT::Hearts:
            card_suit = "Hearts";
            break;
        case SUIT::Diamonds:
            card_suit = "Diamonds";
            break;
        case SUIT::Spades:
            card_suit = "Spades";
            break;
        case SUIT::Clubs:
            card_suit = "Clubs";
            break;
        case SUIT::NONE:
            card_suit = "None";
            break;
    }

    stream << card_rank << " of " << card_suit;
    return stream;
}


