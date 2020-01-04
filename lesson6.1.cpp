#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;

int main(int args, char** argv){
    vector<string>strings;
    string str;

    while(1){
        cout << "Enter the string: ";
        getline(cin, str);
        if(str == "") break;
        strings.push_back(str);
    }
    for(int i = 0; i < strings.size();i +=2){
        cout << setw(8) << left << strings[i];
        if(i == strings.size() - 1) break;
        cout << setw(8)<< right << strings[i+1] << endl;
    }
    return 0;
}
