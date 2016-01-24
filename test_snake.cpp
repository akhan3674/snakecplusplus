#include<iostream>
#include "snake.h"
#include "help.h"
using namespace std;


int main(){
	snake worm(5,5);
	worm.print();
   // help::printpair(worm.getHead());
	//cout<<endl;
	worm.move(make_pair(1,2),1);
	worm.print();
	worm.move(make_pair(2,2),1);
	worm.print();
	worm.move(make_pair(3,2),0);
	worm.print();
	return 0;
}
