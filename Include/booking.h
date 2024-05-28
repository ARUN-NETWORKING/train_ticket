#ifndef Booking_H
#define Booking_H
#include<iostream>
#include<string>
#include<map>
#include<user.h>
#include<ticket.h>


extern map <int ,Train *>train_map;
using namespace std;
class User;
class Booking : public User, public Ticket
{
	private:
		int booking_id;
		string user_id;
		string day;
		//ticket_no,category,bed type 
		map <int, pair<string,string>> booking_map;
		//ticket_no,source,destination
		map<int,pair<string,string>>route_map;
		//ticket_no,source_station_no,destination_station_no
		map<int,pair<int,int>>station_number_map;
		string source,destination;
	public:
		//constructor
		Booking(){}
		
		Booking(int booking_id, string user_id ,string day,int train_id,int start,int end)
		{
			this->booking_id=booking_id;
			this->user_id=user_id;
			this->day=day;
			this->train_id=train_id;
			
			map<int,pair<string,int>>temp_map;
			//station_no & station_name & distance from source


			for (auto it :train_map)
			{
				if(train_id==it.first)
				{
					temp_map=it.second->get_train_route_map();//
					break;
				}
			}
			for (auto iterator :temp_map)
			{
				if(start==iterator.first)
				{
					source=iterator.second.first;
				}
				else if(end==iterator.first)
				{
					destination=iterator.second.first;
				}
			}
			
		}
		//destructor
		~Booking(){}
		void set_ticket_no(int ticket_no,int start,int end)
		{
			station_number_map.insert({ticket_no, make_pair(start,end)});
			route_map.insert(make_pair(ticket_no, make_pair(destination,source)));
		}
		void set_booking_id(int booking_no)
		{
			booking_id=booking_no;
		}
		void insert_map_values(int ticket_no, string category, string bed_type)
		{
			 booking_map.insert(make_pair(ticket_no, make_pair(category, bed_type)));

		}
		void delete_map_values(int num)
		{
			for (auto it = booking_map.begin(); it != booking_map.end(); ) 
			{
    				if (it->first == num)
    				{
        				it = booking_map.erase(it);
    				}
    				else
    				{
        				++it;
    				}
			}

       			
    		}
		
		void set_user_id(string id)
		{
			user_id=id;
		}
		map<int,pair<string, string>> get_map()
		{
			return booking_map;
		}
		map<int,pair<string, string>> get_route_map()
		{
			return route_map;
		}
		map<int,pair<int,int>> get_station_number_map()
		{
			return station_number_map;
		}
		string get_user_id()
		{
			return user_id;
		}
		string get_day()
		{
			return day;
		}
		int get_booking_id()
		{
			return booking_id;
		}
		string get_category(int num)
		{
			for(auto it : booking_map)
			{
				if(it.first==num)
				{
					return it.second.first;
				}
			}
			return NULL;
		}
		string get_source()
		{
			return source;
		}
		string get_destination()
		{
			return destination;
		}
		int get_train_id()
		{
			return train_id;
		}
		
};
#endif


