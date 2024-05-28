#ifndef Traincpp
#define Train_cpp
#include<iostream>
#include<string>
#include<map>
#include<main.h>

using namespace std;





void train_creation()
{
	Train* obj =new Train(1,"YAMUNA");
	obj->insert_map_values(1,"CHENGALPATTU",100);
	obj->insert_map_values(2,"ARIYALUR",200);
	obj->insert_map_values(3,"TRICHY",300);
	train_map[1]=obj;
	
	Train* obj1=new Train(2,"CAUVERY");
	obj1->insert_map_values(1,"DEVAKOTTAI",150);
	obj1->insert_map_values(2,"MANAMADURAI",350);
	obj1->insert_map_values(3,"RAMNAD",500);
	train_map[2]=obj1;
}

#endif
