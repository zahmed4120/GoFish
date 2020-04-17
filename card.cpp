//
// Created by zahme on 4/3/2020.
//

#include "card.h"
#include <iostream>
#include <string>
using namespace std;

// default, ace of spades
Card::Card(){
    myRank = 1;
    mySuit = spades;

}

Card::Card(int rank, Suit s){
    myRank = rank;
    mySuit = s;
}

// return string version e.g. Ac 4h Js
string Card::toString() const{
    string card = "";
    if(myRank == 1){
        card.push_back('A');
    }
    if(myRank == 2){
        card.push_back('2');
    }
    if(myRank == 3){
        card.push_back('3');
    }
    if(myRank == 4){
        card.push_back('4');
    }
    if(myRank == 5){
        card.push_back('5');
    }
    if(myRank == 6){
        card.push_back('6');
    }
    if(myRank == 7){
        card.push_back('7');
    }
    if(myRank == 8){
        card.push_back('8');
    }
    if(myRank == 9){
        card.push_back('9');
    }
    if(myRank == 10){
        card.append("10");
    }
    if(myRank == 11){
        card.push_back('J');
    }
    if(myRank == 12){
        card.push_back('Q');
    }
    if(myRank == 13){
        card.push_back('K');
    }

    if(mySuit == spades){
        card.push_back('s');
    }
    if(mySuit == diamonds){
        card.push_back('d');
    }
    if(mySuit == hearts){
        card.push_back('h');
    }
    if(mySuit == clubs){
        card.push_back('c');
    }

    return card;

}

// true if suit same as c
bool Card::sameSuitAs(const Card& c) const{
    return mySuit == c.mySuit;
}

// return rank, 1..13
int Card::getRank() const{
    return myRank;
}

// return "s", "h",...
string Card::suitString(Suit s) const{
    if(s == spades){
        return "s";
    }
    if(s == hearts){
        return "h";
    }
    if(s == clubs){
        return "c";
    }
    if(s == diamonds){
        return "d";
    }
}

// return "A", "2", ..."Q"
string Card::rankString(int r) const{
    if(r == 1){
        return "A";
    }
    if(r == 2){
        return "2";
    }
    if(r == 3){
        return "3";
    }
    if(r == 4){
        return "4";
    }
    if(r == 5){
        return "5";
    }
    if(r == 6){
        return "6";
    }
    if(r == 7){
        return "7";
    }
    if(r == 8){
        return "8";
    }
    if(r == 9){
        return "9";
    }
    if(r == 10){
        return "10";
    }
    if(r == 11){
        return "J";
    }
    if(r == 12){
        return "Q";
    }
    if(r == 13){
        return "K";
    }
}

bool Card::operator == (const Card& rhs) const{
    return myRank == rhs.myRank;

}

bool Card::operator != (const Card& rhs) const{
    return myRank != rhs.myRank;

}

