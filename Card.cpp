#include<iostream>
#include"Black_JackClasses.h"


Card::Card(Suite nSuite, Value nValue) : cardSuite(nSuite), cardValue(nValue), cardDisplay(true){}

Value Card::getValue() const{
    return cardValue;
}
Suite Card::getSuite() const{
        return cardSuite;
    }
void Card::flip(){
        cardDisplay = !(cardDisplay);
    }


ostream& operator<<(ostream& out, const Card& card){
    if(card.cardDisplay == false){
        out << "XX";
    }
    else {
        out << card.cardSuite << "|";
        out << card.cardValue;
    }
    return out;
}

