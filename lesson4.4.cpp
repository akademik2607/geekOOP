#include<iostream>
#include<vector>
using namespace std;

int cast_num(const vector<int>&A, int baseA){
    int sum1 = A[A.size() - 1];

    for (int i = A.size() - 2; i >= 0;i--) {
        sum1 += (A[i] + 1) * baseA;
    }
    return sum1;
}


vector<int> plus1(const vector<int>&A, int baseA, const vector<int>&B, int baseB, int baseResult){
    int val1, val2, sum, temp;
    val1 = cast_num(A, baseA);
    val2 = cast_num(B, baseB);
    sum = val1 + val2;
    int counter = 0;
    temp = sum;
    while((temp = temp / baseResult) != 0 ){counter++;}
    counter++;
    temp = sum;
    cout << counter << endl;
    vector<int> result(counter);
    for (int i = counter - 1; i >= 0; i--) {
        result[i] = temp % baseResult;
        temp /= baseResult;
    }
    return result;
}


int main(int args, char** argv){
    vector<int> A = {1, 0, 1, 1 };
    vector<int> p = plus1(A, 2, A, 2, 2);
    vector<int>::iterator it;
    for (it = p.begin();it != p.end();it++) {
        cout << *it;
    }
    return 0;
}
