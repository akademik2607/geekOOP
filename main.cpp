#include"Black_JackClasses.h"

int main(){
    int playCount;
    char answer;
    string buf;
    string name;
    Player *p = nullptr;
    vector<Player>players;
    do{
        do{
        cout << "How many players?(1 - 7)" << endl;
        cin >> playCount;
        }while(playCount < 1 || playCount > 7);
        for(int i = 0; i < playCount;i++){
            cout << i + 1 << "name: ";
            cin >> name;
            p = new Player(name);
            players.push_back(*p);
    }
    Game game(players);
    game.Play();

    players.clear();
    p = nullptr;
    cout << endl <<"Do you want play again(y/n)?" << endl;
    cin >> answer;
    getline(cin, buf);
    if(answer != 'y') break;
    }while(true);
    return 0;
}
