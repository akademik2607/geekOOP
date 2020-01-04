#include<iostream>
#include<string>
#include"Black_JackClasses.h"
using namespace std;

GenericPlayer::GenericPlayer(string name) : m_name(name), Hand(){}
GenericPlayer::~GenericPlayer(){

        }
string GenericPlayer::getName() const{
    return m_name;
}
bool GenericPlayer::isBoosted(){
            if(getSum() > BLACK_JACK){
                return true;
            }
            return false;
        }
void GenericPlayer::Bust(){
        cout << m_name << " has a Bust." << endl;
    }


ostream& operator<<(ostream& out, GenericPlayer& player){
    out << player.getName() << " has cadrs:";
    vector <Card*>::iterator it;
    for(it = player.cards.begin();it != player.cards.end(); it++){
        out <<" "<< **it;
    }
    if((*player.cards.begin())->cardDisplay != false){
    out << " sum: " << player.getSum();
    }
    cout << endl;
    return out;
}




