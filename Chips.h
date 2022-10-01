//
// Created by barhamm on 9/30/22.
//

#ifndef BLACKJACK_CPP_CHIPS_H
#define BLACKJACK_CPP_CHIPS_H


class Chips {
public:
    void win_bet() { this->_total += this->_bet; }

    void lose_bet() { this->_total -= this->_bet; }

    int get_total() const { return _total; }

    void set_total(int total) { _total = total; }

    int get_bet() const { return _bet; }

    void set_bet(int bet) { _bet = bet; }

private:
    int _total{};
    int _bet{};
};


#endif //BLACKJACK_CPP_CHIPS_H
