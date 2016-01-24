#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include<iostream>
#include "board.h"
#include "snake.h"
#include "help.h"

class game{
    private:
        board* maze;
        snake* snakey;
        int dimr;
        int dimc;
        int score;
    public:
        game(int dimr,int dimc)
        {   
            this->maze=new board(dimr,dimc);
            this->snakey=new snake(dimr,dimc);
            this->dimr=dimr;
            this->dimc=dimc;
            this->score=0;
        }
        pair<int,int> next_position(pair<int,int> curr,char userin){
            if(userin=='r'){
                return make_pair(curr.first,curr.second+1);
            }
            else if(userin=='l'){
                return make_pair(curr.first,curr.second-1);
            }
            else if(userin=='u'){
                return make_pair(curr.first-1,curr.second);
            }
            else if(userin=='d'){
                return make_pair(curr.first+1,curr.second);
            }
            else{
                cout<<"Wrong Input"<<endl;
            }

        }
        void printboard(){
            int **sPtr=snakey->get_space();
            int **bPtr=maze->get_space();
			for(int i=0;i<dimr;i++)
			{
				for(int j=0;j<dimc;j++){

					if(sPtr[i][j]+bPtr[i][j]==0)
						cout<<" "<<" ";
					else
						cout<<sPtr[i][j]+bPtr[i][j]<<" ";
				}
				cout<<endl;
			}
			cout<<endl;
		}
        bool run(char userin)
        {
            food_generator();
            pair<int,int> shead=snakey->get_head();
            pair<int,int> newcood=next_position(shead,userin);
            int object=maze->get_object(newcood);
            cout<<"Object at next position is "<<object<<endl;
            if(object==1 || snakey->is_body(newcood)){
                cout<<"You hit a wall or body"<<endl;
                return 0;
            }
            if(object==2){
                cout<<"Food"<<endl;
                maze->rm_food();
                snakey->move(newcood,1);
                return 1;
            }
            snakey->move(newcood,0);
            return 1;
        }
        void food_generator(){
             int randr=(rand() % (dimr-1))+1;
             int randc=(rand() % (dimc-1))+1;
             bool success=false;
             if (maze->has_food())
                return;
             while(!success){
                 randr=(rand() % (dimr-1))+1;
                 randc=(rand() % (dimc-1))+1;
                 if (snakey->is_body(make_pair(randr,randc)))
                    success=maze->set_food(make_pair(randr,randc));
            }
        }
};

#endif
