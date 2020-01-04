#include"Black_JackClasses.h"


Game::Game(vector<Player> playerN) : players(playerN), deck() {
    deck.Shuffle();
}

void Game::Play(){
    vector<Player>::iterator it;
    for (it = players.begin();it != players.end();it++) {
        for (int i = 0;i < 2;i++) {
            deck.Deal(*it);
        }
        cout << *it;
    }
    cout << endl;
    for (int i = 0;i < 2;i++) {
         deck.Deal(house);
     }
    cout << endl;

    cout << endl;
    house.FlipFirstCard();
    cout << house;
    for (it = players.begin();it != players.end();it++) {

        cout << *it;
        do{

            if((*it).isBoosted()){
                (*it).Bust();
                break;
            }

            if(!((*it).isHitting())) break;
            deck.Deal(*it);
            cout << *it;

        }while(true);

    }
    house.FlipFirstCard();
    cout << "House cadrs: ";
    do{
        cout << house;
        if(house.isHitting()) deck.Deal(house);
        else break;
    }while(true);

    for(it = players.begin();it != players.end();it++) {
        if((*it).getSum() == house.getSum()){
            (*it).Push();
            cout << endl;
            (*it).clear();
            continue;
        }
        if(((*it).getSum() < house.getSum() && house.getSum() <= BLACK_JACK) || (*it).getSum() > BLACK_JACK){
            (*it).Lose();
            cout << endl;
            (*it).clear();
            continue;
        }
        if((*it).getSum() > house.getSum() && (*it).getSum() <= BLACK_JACK || house.getSum() > BLACK_JACK){
            (*it).Win();
            cout << endl;
            (*it).clear();
        }

    }
}
