#include<iostream>
#include<cstring>
using namespace std;

class OffTheField{
private:
    string message;
    string go;
    int position[2];
public:
    OffTheField(int y, int x, string str) : message("Off The Field!"), go(str){
        position[0] = y;
        position[1] = x;
    }
    getMessage(){
        cout << message << " Current position X: " << position[1] << " Y: "<<position[0] << endl;
        cout << "Go: \"" << go << "\" ";
    }
};

class IllegalCommand{
private:
    string message;
    string go;
    int position[2];
public:
    IllegalCommand(int y, int x, string str) : message("Illegal Command!"), go(str){
        position[0] = y;
        position[1] = x;
    }
    getMessage(){
        cout << message << " Current position X: " << position[1] << " Y: "<<position[0] << endl;
        cout << "Error command: \"" << go << "\" ";
    }
};


class Robo{
private:
    int arr[10][10];
    int pos[2];
public:
    Robo(int x = 0, int y = 0){
        for (int i = 0;i < 10;i++) {
            for (int j = 0;j < 10;j++) {
                arr[i][j] = 0;
            }
        }
        arr[y][x] = 1;
        pos[0] = y;
        pos[1] = x;
    }
    void go(string str){
        if (str != "up" && str != "down" && str != "left" && str != "right") throw IllegalCommand(pos[0], pos[1], str);
        if(str == "up"){

                if(pos[0] - 1 < 0 ) throw OffTheField(pos[0], pos[1], str);
                arr[pos[0]][pos[1]] = 0;
                arr[pos[0] - 1][pos[1]] = 1;
                pos[0]--;

        }
        else if (str == "down") {

                if(pos[0] + 1 == 10 ) throw OffTheField(pos[0], pos[1], str);
                arr[pos[0]][pos[1]] = 0;
                arr[pos[0] + 1][pos[1]] = 1;
                pos[0]++;

        }
        else if (str == "left") {

                if(pos[1] - 1 < 0 ) throw OffTheField(pos[0], pos[1], str);
                arr[pos[0]][pos[1]] = 0;
                arr[pos[0]][pos[1] - 1] = 1;
                pos[1]--;

        }
        else if (str == "right"){

                if(pos[1] + 1 == 10 ) throw OffTheField(pos[0], pos[1], str);
                arr[pos[0]][pos[1]] = 0;
                arr[pos[0]][pos[1] + 1] = 1;
                pos[1]++;

        }
    }
    void getPos(){
        cout << "X: " << pos[1] << " Y: " << pos[0];
    }
};


int main(){
    Robo robo;
    string str;
    do{

    try {
        cout << "Current position: ";
        robo.getPos();
        cout << endl;
        cin >> str;
        if(str == "esc") break;
        robo.go(str);

    } catch (OffTheField &exc) {
        exc.getMessage();
    }
    catch(IllegalCommand &exc){
        exc.getMessage();
    }
    }while(true);
    return 0;
}

