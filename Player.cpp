#include<iostream>
#include"Black_JackClasses.h"

Player::Player(string name) : GenericPlayer(name){}
Player::~Player(){}
bool Player::isHitting(){

    char sym;
    string buffer;
    cout << m_name << ", do you need more cards? (y/n)" << endl;
    cin >> sym;
       getline(cin, buffer);
       return sym != 'y' ?  false : true;
}

void Player::Win() const{
    cout << m_name << " is Win!";
}
void Player::Lose() const{
    cout << m_name << " is Lose!";
}
void Player::Push() const{
    cout << m_name << " tied!";
}
