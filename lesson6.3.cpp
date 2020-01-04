#include<iostream>
#include<string>
using namespace std;

class ManipEnd{
public:
    friend ostream&  operator<<(ostream& out, ManipEnd& obj);
};

ostream& operator<<(ostream& out, ManipEnd& obj){
    out << "\n\n" << flush;
    return out;
}

ManipEnd endll;

int main(int args, char** argv){
    cout << "Hello" << endll;
    cout << "world" << endll;

    return 0;
}
