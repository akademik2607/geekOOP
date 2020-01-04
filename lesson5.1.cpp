#include<iostream>
using namespace std;

template<class T>
class Pair1{
private:
    T first;
    T second;
public:
    Pair1(T f, T s) : first(f), second(s){ }
    T getFirst() const {
        return first;
    }
    T getSecond() const{
        return second;
    }
};

int main(int args, char** argv){
    Pair1<int> p1(6, 9);
    cout << "Pair: " << p1.getFirst() << ' ' << p1.getSecond() << "\n";
    const Pair1<double> p2(3.4, 7.8);
    cout << "Pair: " << p2.getFirst() << ' ' << p2.getSecond() << "\n";
    return 0;
}
