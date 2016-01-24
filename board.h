#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class board
{
    private:
        int dimr;
        int dimc;
        int** space;
        bool food_indicator;
        pair<int,int> food;
    public:
        board(int indimr,int indimc)
        {
            this->dimr=indimr;
            this->dimc=indimc;
            space=new int *[ this->dimr];
            for(int i=0;i< this->dimr;++i)
            {
                this->space[i] = new int[this->dimc];
            }
            for(int i=0;i<dimr;i++)
            {
                for(int j=0;j<dimc;j++)
                {
                    if (i==0 || i==dimr-1 || j==0 || j==dimc-1)
                        this->space[i][j]=1;
                    else
                        this->space[i][j]=0;
                }
            }
            food_indicator=false;
        }
        bool set_food(pair<int,int> food_pair)
        {
            if(space[food_pair.first][food_pair.second]==1)
            {
                return false;
            }
            space[food_pair.first][food_pair.second]=2;
            food_indicator=true;
            food=food_pair;
            return true;
        }
        bool rm_food(){
            space[food.first][food.second]=0;
            food_indicator=false;
        }
        void print()
        {
            for(int i=0;i<this->dimr;i++)
            {
                for(int j=0;j<this->dimc;j++)
                {
                    cout<< this->space[i][j] <<" ";
                }
                cout<<endl;
            }
        }
        int get_object(pair<int,int> cood){
            return space[cood.first][cood.second];
        }
        int** get_space(){
			return space;
		}
		int get_dimr(){
		    return dimr;
		}
		int get_dimc(){
		    return dimc;
		}
		bool has_food(){
		    return food_indicator;
		}

};

#endif