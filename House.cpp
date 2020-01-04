
#include"Black_JackClasses.h"

House::House() : GenericPlayer("House"){}

House::~House(){}

bool House::isHitting(){
    return this->getSum() <= 16 ? true : false;
}

void House::FlipFirstCard(){
    cards[0]->flip();
}
