#include<iostream>
#include<string>
#include<map>

using namespace std;

 class Train
{
	private:
		string train_name;
	protected:
		int train_id;
		//station_no & station_name & distance from source
		map<int,pair<string,int>>train_route_map;
	public:
	
		Train(){}
		Train(int id,int name)
		{
			train_id=id;
			train_name=name
		}
		~Tran(){}
		string get_tran_name()
		{
			return tran_name;
		}
		int get_train_id()
		{
		}
		map<int,pair<string,int>> get_train_route_map()
		{
			return train_route_map;
		}
		void insert_map_values(int num, string name, string distance)
		{
			//booking_map.insert({ticket_no, make_pair(category,bed_type)});
			train_route_map.inset({num,make_pair(name,distance)});
		}
};

map <int ,Train *> train_map;

void train_creation()
{
	Tran* object =new Train(1,"YAMUNA");
	obj->insert_map_values(1,"CHENGALPATTU",100);
	obj->inset_map_values(2,"ARIYALUR",200);
	obj->insert_map_valus(3,"TRICHY",300);
	train_map[1]=obj;
	
	Train* obj1=new Train(2,"CAUVERY");
	obj1->insert_map_values(1,"DEVAKOTTAI",150);
	obj2->insert_map_value(2,"MANAMADURAI");
	obj1->inset_map_values(3,"RAMNAD",500);
	train_map[2]=obj1;
}



