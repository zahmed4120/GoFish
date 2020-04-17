#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <fstream>
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);

int main( )
{
    ofstream oFile;
    oFile.open("gofish_results.txt");
    oFile << "Output Test" << endl;

    int numCards = 7;
    Card *temp1 = nullptr;
    Card *temp2 = nullptr;

    Player p1("Joe");
    Player p2("Jane");

    Deck d;  //create a deck of cards
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    oFile << p1.getName() << " has : " << p1.showHand() << endl;
    oFile << p2.getName() << " has : " << p2.showHand() << endl << endl;
    p1.checkHandForBook(*temp1, *temp2);
    p1.checkHandForBook(*temp1, *temp2);
    p1.checkHandForBook(*temp1, *temp2);
    p2.checkHandForBook(*temp1, *temp2);
    p2.checkHandForBook(*temp1, *temp2);
    p2.checkHandForBook(*temp1, *temp2);

    while(p1.getBookSize() + p2.getBookSize() != 52){
        bool turn = true;
        while(turn){
            if(p1.getHandSize() == 0){
                Card temp = d.dealCard();
                if(temp.getRank() != 0){
                    p1.addCard(temp);
                    oFile << "No more cards in hand" << endl;
                    oFile << p1.getName() << " drew a " << temp.rankString(temp.getRank()) << endl;
                    oFile << "Turn passes to " << p2.getName() << endl << endl;
                    break;
                }
                else{
                    break;
                }
            }
            Card temp = p1.chooseCardFromHand();
            oFile << p1.getName() <<" asks " << p2.getName() <<" - Do you have an " << temp.rankString(temp.getRank()) << " " << endl;
            if(p2.cardInHand(temp)){
                oFile << p2.getName() << " says - Yes I have a " << temp.rankString(temp.getRank()) << endl;
                p1.addCard(p2.removeCardFromHand(temp));
                p1.checkHandForBook(*temp1, *temp2);
		oFile << p2.getName() << " now has hand : " << p2.showHand() << endl;
		oFile << p1.getName() << " now has hand : " << p1.showHand() << endl;
            }
            else{
                oFile << p2.getName() << " says - Go Fish " << endl;
                Card newCard = d.dealCard();
                if(newCard.getRank() != 0){
                    p1.addCard(newCard);
                    oFile << p1.getName() << " drew a " << newCard.rankString(newCard.getRank()) << endl;
                }
                p1.checkHandForBook(*temp1, *temp2);
                turn = false;
                oFile << p1.getName() << " has books : " << p1.showBooks() << endl;
		oFile << p1.getName() << " has hand : " << p1.showHand() << endl;
            }
	    
        }

        oFile << endl;
        turn = true;
        while(turn){
            if(p2.getHandSize() == 0){
                Card temp = d.dealCard();
                if(temp.getRank() != 0){
                    p2.addCard(temp);
                    oFile << "No more cards in hand" << endl;
                    oFile << p2.getName() << " drew a " << temp.rankString(temp.getRank()) << endl;
                    oFile << "Turn passes to " << p1.getName() << endl << endl;
                    break;
                }
                else{
                    break;
                }
            }
            Card temp = p2.chooseCardFromHand();
            oFile << p2.getName() <<" asks " << p1.getName() <<" - Do you have an " << temp.rankString(temp.getRank()) << " " << endl;
            if(p1.cardInHand(temp)){
                oFile << p1.getName() << " says - Yes I have a " << temp.rankString(temp.getRank()) << endl;
                p2.addCard(p1.removeCardFromHand(temp));
                p2.checkHandForBook(*temp1, *temp2);
		oFile << p1.getName() << " now has hand : " << p1.showHand() << endl;
		oFile << p2.getName() << " now has hand : " << p2.showHand() << endl;
            }
            else{
                oFile << p1.getName() << " says - Go Fish " << endl;
                Card newCard = d.dealCard();
                if(newCard.getRank() != 0){
                    p2.addCard(newCard);
                    oFile << p2.getName() << " drew a " << newCard.rankString(newCard.getRank()) << endl;
                }
                p2.checkHandForBook(*temp1, *temp2);
                turn = false;
                oFile << p2.getName() << " has books : " << p2.showBooks() << endl;
		oFile << p2.getName() << " has hand : " << p2.showHand() << endl;
            }
          
        }
        oFile << endl;
    }

    oFile << endl;
    oFile << p1.getName() << " has books : " << p1.showBooks() << endl;
    oFile << p2.getName() << " has books : " << p2.showBooks() << endl;

    if(p1.getBookSize() > p2.getBookSize()){
        oFile << p1.getName() << " wins! " << endl;
        p1.showBooks();
    }
    else if(p1.getBookSize() < p2.getBookSize()){
        oFile << p2.getName() << " wins! " << endl;
        p2.showBooks();
    }
    else{
	oFile << p1.getName() << " and " << p2.getName() << " tied. " << endl;
    }

    oFile << "End Of Game" << endl;

    return EXIT_SUCCESS;
}



void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}



