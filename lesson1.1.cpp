#include<iostream>
#include<cmath>
using namespace std;

class Power{
private:
    double first;
    double second;
public:
    Power() : first(5.0), second(2.0) {}
    void setPower(double first_n, double second_n){
        first = first_n;
        second = second_n;
    }
    double calculate(){
        return pow(first, second);
    }
};

int main(int argc, char** argv){
    Power point;
    cout << point.calculate() << endl;
    point.setPower(2, 5);
    cout << point.calculate();
    return 0;
}
