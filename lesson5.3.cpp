#include<iostream>
#include<string>
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

template<class T1, class T2>
class StringValuePair :  public Pair< T1, T2>{
public:
    StringValuePair(T1 f, T2 s) : Pair<T1, T2>(f, s){}
};

template<class T>
class StringValuePair<string , T> : public Pair<string, T>{
public:
    StringValuePair(string f, T s) : Pair<string, T>(f, s){}
 };

int main(int args, char** argv){
    StringValuePair<string ,int>svp("Amazing", 7);
    cout << "Pair: " << svp.getFirst() << ' '<< svp.getSecond() << '\n';
    return 0;
}
