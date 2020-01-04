#ifndef BLACK_JACK_CLASSES_H
#define BLACK_JACK_CLASSES_H
#define BLACK_JACK 21
#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
#include<cstdlib>
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
public:   //private
    Suite cardSuite;
    Value cardValue;
    bool cardDisplay;
public:
     Card(Suite nSuite, Value nValue);
     Value getValue() const;
     Suite getSuite() const;
     void flip();
     friend ostream& operator<<(ostream& out, const Card& card);
};


class Hand{
public:
    vector<Card*> cards;
    Hand();
    virtual ~Hand();
    void add(Card* newCard);
    void clear();
    int getSum();

};

class GenericPlayer : public Hand{
protected:
    string m_name;
public:
    GenericPlayer(string name);
     ~GenericPlayer() ;
    virtual bool isHitting() = 0;
    string getName() const;
    bool isBoosted();
    void Bust();
    friend ostream& operator<<(ostream& out, GenericPlayer& player);
};

class Player : public GenericPlayer{
public:
    Player(string name);
    ~Player();
    bool isHitting();
    void Win() const;
    void Lose() const;
    void Push() const;
};

class House : public GenericPlayer{
public:
    House();
    ~House();
    bool isHitting();
    void FlipFirstCard();
};

class Deck : public Hand{
public:
    Deck();
    ~Deck();
    void Populate();
    void Shuffle();
    void Deal(Hand& aHand);
    void AddltionalCards(GenericPlayer& aGenericPlayer);
};

class Game{
private:
    Deck deck;
    House house;
    vector <Player> players;
public:
    Game(vector<Player> playerN);
    void Play();
};

#endif
