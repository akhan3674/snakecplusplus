#ifndef HELP_H_INCLUDED
#define HELP_H_INCLUDED

#include<iostream>
#include"snake.h"
#include"board.h"
using namespace std;


class help
{
	public:
		static void printboard(snake* s,board * b){
			int** sPtr=s->get_space();
			int** bPtr=b->get_space();
			int dimr=b->get_dimr();
			int dimc=b->get_dimc();
			for(int i=0;i<dimr;i++)
			{
				for(int j=0;j<dimc;j++){
					cout<<sPtr[i][j]+bPtr[i][j]<<" ";
				}
				cout<<endl;
			}
			cout<<endl;
		}
};

#endif
