#include"Black_JackClasses.h"

Deck::Deck() : Hand(){
    Populate();

}

Deck::~Deck(){

}

void Deck::Populate(){
    cards.reserve(52);
    for (int i = HEART;i < 4;i++) {
        for (int j = ACE;j < 14;j++) {
            Card *p;
            if(j >= 10){        //  Эта память освобождается в деструкторе ~Hand()
                p = new Card((Suite)i, (Value)10);
            }
            else {
                p = new Card((Suite)i, (Value)j);
            }


            cards.push_back(p);
        }
    }
}

void Deck::Shuffle(){
    srand(unsigned(time(0)));
    random_shuffle(cards.begin(), cards.end());
}

void Deck::Deal(Hand& aHand){
    aHand.add(cards.back());
    cards.pop_back();
}

void Deck::AddltionalCards(GenericPlayer& aGenericPlayer){
    while (aGenericPlayer.isHitting()) {
        Deal(aGenericPlayer);
    }
}

