#include<iostream>
#include<vector>
#define INPUT 10
using namespace std;

int main(int args, char** argv){
    vector <int> data(INPUT);
    vector <int> counter;
    cout << "Enter " << INPUT << " numbers." << endl;
    for (int i = 0;i < INPUT;i++) {
        cout << i + 1 << ": ";
        cin >> data[i];
        if(counter.empty()){
            counter.push_back(data[i]);
        }
        else {
            int flag = 0;
            for(int j = 0; j < counter.size();j++){
                if(counter[j] == data[i]){
                    flag = 1;
                    break;
                }
            }
            if(!flag){
                counter.push_back(data[i]);
            }
        }
    }
    //Вывод результата
    for (int i = 0;i < INPUT;i++) {
        cout << data[i] << " ";
    }
    cout << endl;
    cout << "Unic: ";
    for (int i = 0;i < counter.size();i++) {
        cout << counter[i] << " ";
    }
    cout << endl;
    cout << "Unic elements: " << counter.size();
    return 0;
}
