#include<iostream>
using namespace std;

template<class T1, class T2>
class Pair{
private:
    T1 first;
    T2 second;
public:
    Pair(T1 f, T2 s) : first(f), second(s){}
        T1 getFirst() const {
            return first;
        }
        T2 getSecond() const {
            return second;
        }
};

int main(int args, char** argv){
    Pair<int, double> p1(6, 7.8);
    cout << "Pair: " << p1.getFirst() << ' ' << p1.getSecond() << "\n";
    const Pair<double, int> p2(3.4, 5);
    cout << "Pair: " << p2.getFirst() << ' ' << p2.getSecond() << "\n";
    return 0;
}
