#include<iostream>

#include"Black_JackClasses.h"

Hand::Hand(){
        cards.reserve(7);
    }
Hand:: ~Hand(){
        clear();
    }
void Hand::add(Card* newCard){
        cards.push_back(newCard);
    }
void Hand::clear(){
            vector<Card*>::iterator it = cards.begin();
            for (;it != cards.end();it++) {
            delete *it;
            *it = 0;
            }
            cards.clear();
        }
int Hand::getSum(){
            int sum = 0;
            int Ace_flag = 0;
            vector<Card*>::iterator it;
            it = cards.begin();
            while(it != cards.end()) {
                if((*it)->getValue() == ACE) Ace_flag++;
                sum += (*it)->getValue();
                it++;
            }
            if(Ace_flag != 0){
                for (int i =0;i < Ace_flag;i++) {
                    if(sum + 10 <= BLACK_JACK){
                        sum += 10;
                    }
                }
            }
            return sum;
        }
