#ifndef ADD_H_INCLUDED
#define ADD_H_INCLUDED

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct node{
		node* next;
		pair<int,int> data;
		node(pair<int,int> indata, node* innext)
		{
			data=indata;
			next=innext;
			
		}
};

class snake{
	private:
		node * head=NULL;
		node * tail=NULL;
		int ** space;
	public:
		snake(int dimr,int dimc)
		{
			space=new int *[dimr];
            for(int i=0;i< dimr;++i)
            {
                space[i] = new int[dimc];
            }
            for(int i=0;i<dimr;i++)
            {
                for(int j=0;j<dimc;j++)
                {
                        space[i][j]=0;
                }
            }
			tail=new node(make_pair(1,1),NULL);
			head=tail;
            space[1][1]=3;
		}
		void move(pair<int,int> cood,bool food)
		{
			space[cood.first][cood.second]=3;
			tail-> next= new node(cood,NULL);
			tail=tail->next;
			node * temp;
			if (food==0)
			{
				space[head->data.first][head->data.second]=0;
				temp=head;
				head=head->next;
				delete temp;
				temp=NULL;
				 
			}
			
		}
		pair< int,int > get_head(){
			return tail->data;
		}
		bool is_body(pair<int,int> cood){
			if(space[cood.first][cood.second]==3){
				return 1;
			}
			return 0;
		}
		void print(){
			cout << "-=";
			node * ptr=head;
			while(ptr!=NULL)
			{
				cout << "(" << ptr->data.first << "," << ptr->data.second << ")" << "=";
				ptr=ptr->next;
			}
			cout<<"=<"<<endl;
		}
		int** get_space(){
			return space;
		}
};

#endif