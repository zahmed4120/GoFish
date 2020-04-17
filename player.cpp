//
// Created by zahme on 4/3/2020.
//

#include "player.h"
#include <iostream>
#include <string>
#include <vector>
#include <ctime>


#include "card.h"
using namespace std;

Player::Player(){
    myName = "";
}

//adds a card to the hand
void Player::addCard(Card c){
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2){
    myBook.push_back(c1);
    myBook.push_back(c2);
    int i = 0;
    while(i < myHand.size()){
        if(c1 == myHand[i] && c1.sameSuitAs(myHand[i])){
            myHand.erase(myHand.begin() + i);
        }
        if(c2 == myHand[i] && c2.sameSuitAs(myHand[i])){
            myHand.erase(myHand.begin() + i);
        }
        i ++;
    }
}

//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

bool Player::checkHandForBook(Card &c1, Card &c2){
    int standingIndex = 0;
    int movingIndex;
    while(standingIndex < myHand.size()){
        movingIndex = standingIndex + 1;
        while(movingIndex < myHand.size()){
            if(myHand[standingIndex] == myHand[movingIndex]){
                bookCards(myHand[standingIndex], myHand[movingIndex]);
                return true;
            }
            movingIndex ++;
        }
        standingIndex ++;
    }
    return false;

}

//OPTIONAL
// comment out if you decide to not use it
//Does the player have a card with the same rank as c in her hand?
bool Player::rankInHand(Card c) const{

}

//uses some strategy to choose one card from the player's
//hand so they can say "Do you have a 4?"
Card Player::chooseCardFromHand() const{
    unsigned int currentTime = (unsigned) time(nullptr);
    srand(currentTime);
    long randomNum = (rand() % myHand.size());
    return myHand[randomNum];

}

//Does the player have the card c in her hand?
bool Player::cardInHand(Card c) const{
    int i = 0;
    while(i < myHand.size()){
        if(myHand[i] == c){
            return true;
        }
        i ++;
    }
    return false;

}

//Remove the card c from the hand and return it to the caller
Card Player::removeCardFromHand(Card c){
    int i = 0;
    while(myHand[i] != c){
        i ++;
    }
    Card temp = myHand[i];
    myHand.erase(myHand.begin() + i);
    return temp;

}

string Player::showHand() const{
    int i = 0;
    string hand = "";
    while(i < myHand.size()){
        hand.append(myHand[i].toString());
        hand.append(" ");
        i ++;
    }
    return hand;
}
string Player::showBooks() const{
    int i = 0;
    string books = "";
    while(i < myBook.size()){
        books.append(myBook[i].toString());
        books.append(" ");
        i ++;
    }
    return books;

}

int Player::getHandSize() const{
    return myHand.size();

}
int Player::getBookSize() const{
    return myBook.size();
}

//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

bool Player::checkHandForPair(Card &c1, Card &c2){

}

//OPTIONAL
// comment out if you decide to not use it
//Does the player have a card with the same rank as c in her hand?
//e.g. will return true if the player has a 7d and the parameter is 7c

bool Player::sameRankInHand(Card c) const{

}
