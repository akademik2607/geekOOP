#include<iostream>
#include<cassert>
using namespace std;

class ArrayInt{
private:
    int *data;
    int lenght;
public:
    ArrayInt() : data(nullptr), lenght(0){}
    ArrayInt(int _lenght) : lenght(_lenght){
        assert(_lenght >= 0);
        if(lenght > 0)data = new int[lenght];
        else data = nullptr;
    }
    ~ArrayInt(){
        delete [] data;
    }
    void erase(){
        delete [] data;
        data = nullptr;
        lenght = 0;
    }
    int getLenght() const {
        return lenght;
    }
    int& operator[](int index){
        assert(index >= 0 && index < lenght);
        return data [index];
    }
    void resize(int newLenght){
        if(newLenght == lenght) return;
        if(newLenght <= 0){
            erase();
        }
        else {
            int *newData = new int[newLenght];
            int elementToCopy = newLenght > lenght? lenght : newLenght;
            for (int i =0;i < elementToCopy; i++) {
                newData[i] = data[i];
            }
            delete [] data;
            data = newData;
            lenght = newLenght;
        }
    }
    void insert(int index, int value){
        assert(index >= 0);
        if(index <= lenght){
            int* newData = new int[lenght + 1];
            for (int i = 0;i < index; i++) {
                newData[i] = data[i];
            }
            newData[index] = value;
            for (int i = index + 1;i < lenght + 1;i++) {
                newData[i] = data[i - 1];
            }
            delete [] data;
            data = newData;
            lenght++;
        }
        else {
            int* newData = new int[index + 1];
            for (int i = 0;i < lenght; i++) {
                newData[i] = data[i];
            }
            for (int i = lenght;i < index;i++) {
                newData[i] = 0;
            }
            newData[index] = value;
            delete [] data;
            data = newData;
            lenght = index + 1;
        }
    }
    void pushBack(int value){
        int* newData = new int[lenght + 1];// Понимаю, что не эффективно выделять память и копировать значения при каждом
        // добавлении элемента но, просто тогда пришлось бы и конструкторы переписать.
        for (int i = 0;i < lenght;i++) {
            newData[i] = data[i];
        }
        newData[lenght] = value;
        delete [] data;
        data = newData;
        lenght++;
    }
    int popBack(){
        int val = data[lenght - 1];
        int* newData = new int [lenght - 1];
        for (int i = 0;i < lenght - 1;i++) {
            newData[i] = data[i];
        }
        delete [] data;
        data = newData;
        lenght--;
        return val;
    }
    void sort(){
        for(int i = 0;i < lenght - 1; i++){
            for (int j = 0;j < lenght - 1;j++) {
                if(data[j] > data[j + 1]){
                    data[j] ^= data[j + 1];
                    data[j + 1] ^= data[j];
                    data[j] ^= data[j + 1];
                }
            }
        }
    }
};


int main(int args, char** argv){
    ArrayInt arr(10);
    arr.getLenght();
    cout << endl;
    for (int i = 0;i < arr.getLenght();i++) {
        arr[i] = i;
        cout << arr[i] << " ";
    }
    cout << endl;
    arr.insert(3,15);
    for (int i = 0;i < arr.getLenght();i++) {

        cout << arr[i] << " ";
    }
    cout << endl;
    arr.insert(20, 150);
    for (int i = 0;i < arr.getLenght();i++) {

        cout << arr[i] << " ";
    }
    cout << endl;
    arr.sort();
    for (int i = 0;i < arr.getLenght();i++) {

        cout << arr[i] << " ";
    }
    return 0;
}
