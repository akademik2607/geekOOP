#include<iostream>
#include<string>
#include<cmath>
#define SIZE_INT 2147483647
using namespace std;

int main(int args, char** argv){
    string num;

    while(1){
        int flag = 0;
        cout << "Enter the num: ";
        getline(cin, num);
        if(num[0] != '-' && !isdigit(num[0])){
            flag = 1;
            cout << "Error!";
            continue;
        }
        for (int i = 1;i < num.size();i++) {
            if(!isdigit((int)num[i])){
                flag = 1;
                break;
            }
    }
        if(abs(atoll(num.c_str())) > SIZE_INT) flag = 1;
    if(!flag) break;
    cout << "Error!" << endl;
    }
    cout << num;
    return 0;
}


