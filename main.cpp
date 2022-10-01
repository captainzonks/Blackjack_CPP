#include <iostream>

#include "Deck.h"
#include "Chips.h"
#include "Hand.h"

bool PLAYING = true;

void take_bet(Chips &chips);

void hit(Deck& deck, Hand& hand);

void hit_or_stand(Deck& deck, Hand& hand);

void show_some(Hand& player_hand, Hand& dealer_hand);

void show_all(Hand& player_hand, Hand& dealer_hand);

void player_busts(Chips& player_chips);

void player_wins(Chips& player_chips);

void dealer_busts(Chips& player_chips);

void dealer_wins(Chips& player_chips);

void push();


int main() {

    std::cout << "Welcome to Blackjack!" << std::endl;

    Chips player_chips;
    player_chips.set_total(100);

    while (true) {
        Deck deck;
        deck.shuffle();

        Hand player_hand;
        player_hand.add_card(deck.deal());
        player_hand.add_card(deck.deal());

        Hand dealer_hand;
        dealer_hand.add_card(deck.deal());
        dealer_hand.add_card(deck.deal());

        take_bet(player_chips);
        show_some(player_hand, dealer_hand);

        while (PLAYING) {
            hit_or_stand(deck, player_hand);
            show_some(player_hand, dealer_hand);

            if (player_hand.get_value() > 21) {
                player_busts(player_chips);
                break;
            }
        }

        if (player_hand.get_value() <= 21) {
            while (dealer_hand.get_value() < 17) {
                hit(deck, dealer_hand);
            }

            show_all(player_hand, dealer_hand);

            if (dealer_hand.get_value() > 21) {
                dealer_busts(player_chips);
            } else if (dealer_hand.get_value() > player_hand.get_value()) {
                dealer_wins(player_chips);
            } else if (dealer_hand.get_value() < player_hand.get_value()) {
                player_wins(player_chips);
            } else {
                push();
            }
        }
        std::cout << "\nPlayer's winnings stand at " << player_chips.get_total() << std::endl;

        std::cout << "\nWould you like to play another hand? ('y' or 'n') ";
        char answer;
        std::cin >> answer;

        if (tolower(answer) == 'y') {
            PLAYING = true;
            continue;
        }
        else {
            std::cout << "\nThanks for playing.";
            break;
        }
    }

    return 0;
}

void take_bet(Chips &chips) {
    while (true) {
        std::cout << "\nHow many chips would you like to bet? ";
        int bet{};
        std::cin >> bet;

        if (bet > chips.get_total()) {
            std::cout << "\nSorry, your bet can't exceed " << chips.get_total() << std::endl;
        } else {
            chips.set_bet(bet);
            break;
        }
    }
}

void hit(Deck& deck, Hand& hand) {
    hand.add_card(deck.deal());
    hand.adjust_for_aces();
}

void hit_or_stand(Deck& deck, Hand& hand) {
    while (true) {
        std::cout << "\nWould you like to Hit or Stand? ('h' or 's') ";
        char answer;
        std::cin >> answer;
        if (tolower(answer) == 'h') {
            hit(deck, hand);
        } else if (tolower(answer) == 's') {
            std::cout << "Player stands. Dealer is playing.";
            PLAYING = false;
            break;
        } else {
            std::cout << "Please try again.";
            continue;
        }
        break;
    }
}

void show_some(Hand& player_hand, Hand& dealer_hand) {
    std::cout << "\nDealer's Hand" << std::endl;
    std::cout << "---------------" << std::endl;
    std::cout << " <card hidden>" << std::endl;
    std::cout << dealer_hand.get_cards()[1];
    std::cout << "\n\nPlayer's Hand" << std::endl;
    std::cout << "-----------------" << std::endl;
    for (Card card: player_hand.get_cards()) {
        std::cout << card << std::endl;
    }
}

void show_all(Hand& player_hand, Hand& dealer_hand) {
    std::cout << "\nDealer's Hand" << std::endl;
    std::cout << "---------------" << std::endl;
    for (Card card: dealer_hand.get_cards()) {
        std::cout << card << std::endl;
    }
    std::cout << "\n\nPlayer's Hand" << std::endl;
    std::cout << "-----------------" << std::endl;
    for (Card card: player_hand.get_cards()) {
        std::cout << card << std::endl;
    }
}

void player_busts(Chips& player_chips) {
    std::cout << "\nPlayer busts. Dealer wins." << std::endl;
    player_chips.lose_bet();
}

void player_wins(Chips& player_chips) {
    std::cout << "\nDealer busts. Player wins." << std::endl;
    player_chips.win_bet();
}

void dealer_busts(Chips& player_chips) {
    std::cout << "\nDealer busts. Player wins." << std::endl;
    player_chips.win_bet();
}

void dealer_wins(Chips& player_chips) {
    std::cout << "\nPlayer busts. Dealer wins." << std::endl;
    player_chips.lose_bet();
}

void push() {
    std::cout << "\nDealer and Player tie. It's a push" << std::endl;
}