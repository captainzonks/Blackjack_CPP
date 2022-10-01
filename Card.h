//
// Created by barhamm on 9/30/22.
//

#ifndef BLACKJACK_CPP_CARD_H
#define BLACKJACK_CPP_CARD_H

#include <ostream>

enum class SUIT {
    Hearts,
    Diamonds,
    Spades,
    Clubs,
    NONE
};

enum class RANK {
    One,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
    NONE
};

class Card {
public:
    Card() = delete;

    Card(SUIT suit, RANK rank);

    void set_value();

    friend std::ostream& operator<<(std::ostream& stream, const Card& card);

    SUIT get_suit() { return _suit; }

    RANK get_rank() { return _rank; }

    int get_value() const { return _value; }

private:
    SUIT _suit;
    RANK _rank;
    int _value{};
};


#endif //BLACKJACK_CPP_CARD_H
