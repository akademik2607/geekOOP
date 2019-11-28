#include<iostream>
#define STACK_LENGTH 10
using namespace std;

class Stack{
private:
    int arr[STACK_LENGTH];
    int length;
public:
    Stack(){}
    void reset(){
        for (int i = 0;i < STACK_LENGTH;i++) {
            arr[i] = 0;
        }
        length = 0;
    }
    bool push(int value){
        if(length == STACK_LENGTH) return false;
        length++;
        arr[length - 1] = value;
    }
    int pop(){
        if(length == 0){
            cout << "Stack is empty!" << endl;
            return 0;
        }
        int res = arr[length - 1];
        length--;
        return res;
    }
    void print(){
        cout << "(";
        for (int i = 0;i < length;i++) {
            cout << arr[i] << " ";
        }
        cout << ")"<< endl;
    }
};

int main(int argc, char** argv){
    Stack stack;
        stack.reset();
        stack.print();

        stack.push(3);
        stack.push(7);
        stack.push(5);
        stack.print();

        stack.pop();
        stack.print();

        stack.pop();
        stack.pop();
        stack.print();

    return 0;
}
