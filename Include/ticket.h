#ifndef Ticket_H
#define Ticket_H
#include<iostream>
#include<string>
#include<map>
#include<vector>


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
		Train(int id,string name)
		{
			train_id=id;
			train_name=name;
		}
		~Train(){}
		string get_tran_name()
		{
			return train_name;
		}
		int get_train_id()
		{
			return train_id;
		}
		map<int,pair<string,int>> get_train_route_map()
		{
			return train_route_map;
		}
		void insert_map_values(int num, string name, int distance)
		{
			//booking_map.insert({ticket_no, make_pair(category,bed_type)});
			train_route_map.insert({num,make_pair(name,distance)});
		}
};

class Ticket : public Train
{
	private:
		int fare;
		string status="FREE";
	protected:
		string day;
		string category;
		string bed_type;
		int ticket_no;
		int passenger_count=0;
		//user_id,source,destination
		map<string,pair<int,int>>seat_holder_map;
		vector<int>stations;
	public:
		//constructor
		Ticket(){};
		Ticket(int ticket_no, string category, string bed_type,string day, int fare,int id)
		{
			this->ticket_no=ticket_no;
			this->category=category;
			this->bed_type=bed_type;
			this->fare=fare;
			this->day=day;
			train_id=id;
		}
		//destructor
		~Ticket(){}
		//setters and getters
		void set_status(string status)
		{
			this->status=status;
		}
		string get_status()
		{
			return status;
		}
		string get_category()
		{
			return category;
		}
		int get_fare()
		{
			return fare;
		}
		string get_bed_type()
		{
			return bed_type;
		}
		int get_ticket_no()
		{
			return ticket_no;
		}
		void insert_seat_holder_map(string a,int b,int c)
		{
			seat_holder_map.insert({a,make_pair(b,c)});
		}
		map<string,pair<int,int>>* get_seat_holder_map()
		{
			return &seat_holder_map;
		}
		void increase_passenger_count()
		{
			++passenger_count;
		}
		int get_passenger_count()
		{
			return passenger_count;
		}
		void decrease_passenger_count()
		{
			--passenger_count;
		}
		vector<int>* get_station()
		{
			return &stations;
		}
};


static int ticket_no=1000,train1_id=1,train2_id=2, 
sun_ac_up=30, sun_ac_mid=30 , sun_ac_low=30, sun_sleep_up=60, sun_sleep_mid=60, sun_sleep_low=60, sun_sit=200,
mon_ac_up=30, mon_ac_mid=30 , mon_ac_low=30, mon_sleep_up=60, mon_sleep_mid=60, mon_sleep_low=60, mon_sit=200,
tue_ac_up=30, tue_ac_mid=30 , tue_ac_low=30, tue_sleep_up=60, tue_sleep_mid=60, tue_sleep_low=60, tue_sit=200,
wed_ac_up=30, wed_ac_mid=30 , wed_ac_low=30, wed_sleep_up=60, wed_sleep_mid=60,  wed_sleep_low=60, wed_sit=200,
thu_ac_up=30, thu_ac_mid=30 , thu_ac_low=30, thu_sleep_up=60, thu_sleep_mid=60, thu_sleep_low=60, thu_sit=200,
fri_ac_up=30, fri_ac_mid=30 , fri_ac_low=30, fri_sleep_up=60, fri_sleep_mid=60, fri_sleep_low=60, fri_sit=200,
sat_ac_up=30, sat_ac_mid=30 , sat_ac_low=30, sat_sleep_up=60,  sat_sleep_mid=60, sat_sleep_low=60, sat_sit=200;



struct ticket
{
	int train_id;
	int ticket_no;
	string day;
	Ticket * pointer;
	struct ticket *left;
	struct ticket *right;
	
	ticket(){}
	ticket(Ticket *ptr, int num, string d,int id)
	{
		pointer=ptr;
		ticket_no=num;
		day=d;
		left=nullptr;
		right=nullptr;
		train_id=id;
	}
};





#endif


