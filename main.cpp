#include<iostream>
#include <curses.h>
#include"game.h"

using namespace std;

int main(){
    game mygame=game(10,10);
    char userin;
    int alive=1;
    while(alive){
        mygame.printboard();    
        cout<<"Input Your Direction: ";
        cin>>userin;
        alive=mygame.run(userin);
    }
    return 0;
}
