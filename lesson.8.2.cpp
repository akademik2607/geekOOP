#include<iostream>
using namespace std;

class Ex{
public:
    double x;
    Ex(double num) : x(num){}

};

class Bar{
private:
    double y;
public:
    Bar(double num = 0) : y(num){}
    void setBar(double a){
        if(a + y > 100) throw Ex(a * y);
        y = a;
    }
};

int main(){
    int data;
    Bar bar;
    cin >> data;
    while(data != 0){
        try {
            bar.setBar(data);
        } catch (Ex & ex) {
            cout << "Error: "<< ex.x << endl;
        }
        cin >> data;
    }
    return 0;
}
