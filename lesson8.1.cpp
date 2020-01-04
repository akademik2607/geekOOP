#include<iostream>

using namespace std;

class DivisionByZero{
private:
    string message;
public:
    DivisionByZero() : message("Division by zero!"){}
    string getMessage() const{
        return message;
    }
};

void myDiv(int a, int b){
    try {
        if(b == 0) throw DivisionByZero();
        cout << a / b;

    } catch (DivisionByZero &ex) {
        cout << ex.getMessage();
    }
}
int main(int args, char**argv){
    myDiv(1, 0);
    return 0;
}
