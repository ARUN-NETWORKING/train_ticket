#include<iostream>
#include<string>
#include<map>
using namespace std;

class Train;

class Ticket;

Ticket *ticket_dummy=nullptr;

//map <int ,Train *>train_map;

static int ticket_no=1000,train1_id=1,train2_id=2, 
sun_ac_up=30, sun_ac_mid=30 , sun_ac_low=30, sun_sleep_up=60, sun_sleep_mid=60, sun_sleep_low=60, sun_sit=200,
mon_ac_up=30, mon_ac_mid=30 , mon_ac_low=30, mon_sleep_up=60, mon_sleep_mid=60, mon_sleep_low=60, mon_sit=200,
tue_ac_up=30, tue_ac_mid=30 , tue_ac_low=30, tue_sleep_up=60, tue_sleep_mid=60, tue_sleep_low=60, tue_sit=200,
wed_ac_up=30, wed_ac_mid=30 , wed_ac_low=30, wed_sleep_up=60, wed_sleep_mid=60  wed_sleep_low=60, wed_sit=200,
thu_ac_up=30, thu_ac_mid=30 , thu_ac_low=30, thu_sleep_up=60, thu_sleep_mid=60, thu_sleep_low=60, thu_sit=200,
fri_ac_up=30, fri_ac_mid=30 , fri_ac_low=30, fri_sleep_up=60, fri_sleep_mid=60, fri_sleep_low=60, fri_sit=200,
sat_ac_up=30, sat_ac_mid=30 , sat_ac_low=30, sat_sleep_up=60  sat_sleep_mid=60, sat_sleep_low=60, sat_sit=200;



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
		train_id=id
	}
};

struct ticket * head=nullptr;


