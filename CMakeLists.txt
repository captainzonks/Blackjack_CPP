cmake_minimum_required(VERSION 3.23)
project(Blackjack_CPP)

set(CMAKE_CXX_STANDARD 14)

add_executable(Blackjack_CPP main.cpp Card.cpp Card.h Deck.cpp Deck.h Hand.cpp Hand.h Chips.cpp Chips.h)
