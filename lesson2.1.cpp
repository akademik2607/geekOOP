#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int words(string text){
    int space1 = 0;
    int space2 = 0;
    int word = 1;

    for (int i = 1; i < text.length(); i++) {
        if(text[i] == ' '){
            if(space1 <= space2) space1 = i;
            else space2 = i;
            if(abs(space1 - space2) == 1){}
            else word++;
        }
    }
    return word;
}

class Book{
protected:
    string title;
    string author;
    double cost;
public:
    Book( ){
        string t;
        string a;
        double c;
        while(1){
            cout << "Title: ";
            getline(cin, t);
            if(t[0] > '0' && t[0] < '9') cout << "Error!" << endl;
            else break;
        }
        while(1){
            cout << "Author: ";
            getline(cin, a);
            if(words(a) > 2) cout << "Error!" << endl;
            else break;
        }
        while(1){
            cout << "Cost: ";
            cin >> c;
            if(c <= 0) cout <<"Error!" << endl;
            else break;
        }
        title = t;
        author = a;
        cost = c;
        getline(cin, t);
    }
    void setTitle(){
        string t;
        while(1){
            cout << "Title: ";
            getline(cin, t);
            if(t[0] > '0' && t[0] < '9') cout << "Error!" << endl;
        }
        title = t;
    }
    void setAuthor(){
        string a;
        while(1){
            cout << "Author: ";
            getline(cin, a);
            if(words(a) > 2) cout << "Error!" << endl;
            else break;
        }
        author = a;
    }
    void setCost(){
        double c;
        string buf;
        while(1){
            cout << "Cost: ";
            cin >> c;
            if(c <= 0) cout <<"Error!" << endl;
            else break;
        }
        cost = c;
        getline(cin, buf);
    }
    void showBook(){
        cout << "Title: " << title;
        cout << " Author: " << author;
        cout << " Cost: " << cost << endl;
        cout << endl;
    }
    string getTitle(){return title;}
    string getAuthor(){return author;}
    double getCost(){return cost;}

};


class GoldenEditionBook : public Book{
public:
    GoldenEditionBook() : Book() {
        cost = getCost() + (getCost() / 100 * 30);
    }
};

int main(int argc, char** argv){
    Book book1;
    book1.showBook();
    GoldenEditionBook book2;
    book2.showBook();
    return  0;
}
