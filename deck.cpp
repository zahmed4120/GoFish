//
// Created by zahme on 4/3/2020.
//

#include "deck.h"
#include "card.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

// pristine, sorted deck
Deck::Deck(){
    int deckIndex = 0;
    for(int i = 1; i <= 13; i ++){
        myCards[deckIndex] = Card(i, Card::spades);
        deckIndex ++;
    }
    for(int i = 1; i <= 13; i ++){
        myCards[deckIndex] = Card(i, Card::hearts);
        deckIndex ++;
    }
    for(int i = 1; i <= 13; i ++){
        myCards[deckIndex] = Card(i, Card::diamonds);
        deckIndex ++;
    }
    for(int i = 1; i <= 13; i ++){
        myCards[deckIndex] = Card(i, Card::clubs);
        deckIndex ++;
    }
    myIndex = 0;
}

// shuffle the deck, all 52 cards present
void Deck::shuffle(){
    unsigned int currentTime = (unsigned) time(nullptr);
    srand(currentTime);
    for(int i = 0; i < 416; i ++){
        long randomNum = (rand() % 52);
        Card temp = myCards[0];
        myCards[0] = myCards[randomNum];
        myCards[randomNum] = temp;

    }

}

// get a card, after 52 are dealt, fail
Card Deck::dealCard(){
    if(size() == 0){
        Card fail(0, Card::spades);
        return fail;
    }

    myIndex ++;
    return myCards[myIndex - 1 ];

}

// # cards left in the deck
int Deck::size() const{
    return SIZE - myIndex;

}
