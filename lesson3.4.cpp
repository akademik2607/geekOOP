#include<iostream>
using namespace std;

enum Suite{
    HEART,   //черви
    DIAMOND, //буби
    CLUB,    //трефы
    SPADE    //пики
};

enum Value{
    ACE = 1,
    TWO = 2,
    THREE = 3,
    FOUR = 4,
    FIVE = 5,
    SIX = 6,
    SEVEN = 7,
    EIGHT = 8,
    NINE = 9,
    TEN = 10,
    JACK = 10,
    GUEEN = 10,
    KING = 10
};

class Card{
private:
    Suite cardSuite;
    Value cardValue;
    bool cardDisplay;
public:
    Card(Suite nSuite, Value nValue)
        : cardSuite(nSuite), cardValue(nValue), cardDisplay(false){}
    Value getValue(){
        return cardValue;
    }
    Suite getSuite(){
        return cardSuite;
    }
    void Flip(){
        cardDisplay = !(cardDisplay);
    }
};

int main(int argv, char** args){
    Card card(CLUB, SEVEN);
    cout << card.getValue() << endl;
    cout << card.getSuite() << endl;
    return 0;
}
