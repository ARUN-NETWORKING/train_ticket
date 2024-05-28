#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<main.h>
#include <algorithm>
#include<iomanip>

using namespace std;
//user_id,booking object
multimap<string,Booking *>ticket_map;



bool user_history(string id)
{
	auto ite = ticket_map.find(id);
    if (ite != ticket_map.end())
    {
    	cout<<"| BOOKING_ID |    DAY    | TICKET_NO | CATEGORY | BED_TYPE |"<<endl;
    	cout<<"------------------------------------------------------------"<<endl;
		for(auto it : ticket_map)
		{
			if(it.first==id)
			{
				for(auto iterator : it.second->get_map())
				{
					cout<<"|    "<<it.second->get_booking_id()<<"    |  "<<it.second->get_day()<<"    |  "<<iterator.first<<" | "<<iterator.second.first<<" |  "<<iterator.second.second<<"  |"<<endl;
				}
			}
		}
		cout<<"------------------------------------------------------------"<<endl;
		return true;
	}
	else
	{
		cout<<"USER HASN'T BOOKED ANY TICKETS!!!!"<<endl;
		return false;
		
		
	}
}


void cancel_ticket(User*user_obj)
{
	string id=user_obj->get_user_id();
	
	bool exists=user_history(id);
	if(!exists)
	{
		cout<<"!!!NO TICKETS HAS BEEN BOOKED TO CANCEL!!!"<<endl;
		return;
	}
	int booking_id;
	cout<<"Enter the booking id:"<<endl;
	cin>>booking_id;
	int train_id,start,end;
	string day,category;
	bool present =false;
	cout<<"ENTER THE TRAIN ID IN WHICH YOU WANT TO CANCEL THE TICKET :"<<endl;
	cin>>train_id;
	cout<<"ENTER THE DAY IN WHICH YOU WANT TO CANCEL THE BOOKED TICKET :"<<endl;
	
	cin>>day;
	cout<<"ENTER THE TICKET NUMBER YOU WANT TO CANCEL :"<<endl;
	int num;
	cin>>num;
	map<int,pair<int,int>>s_d_num;
	for(auto it : ticket_map){
		s_d_num=it.second->get_station_number_map();
		for(auto ite:s_d_num)
		{
		int check=0;
		
		if(ite.first==num)
		{
			check=num;
			start=ite.second.first;
			end=ite.second.second;
		}
		}
		}
		if(check==0)
		{
			cout<<"No ticket is on the given ticket number:"<<endl;
			return;
			
		}
		 
	
	for(auto it : ticket_map)
	{
		//user_id,booking object
		if(it.first==id && it.second->get_train_id()==train_id && it.second->get_booking_id()==booking_id)
		{
			if(it.second->get_day()==day)
			{
				present=true;
				category=it.second->get_category(num);
			
				it.second->delete_map_values(num);
			}
		}
	}
	
	if(!present)
	{
		cout<<"!!! INCORRECT DETAILS !!!"<<endl;
		return;
	}
	struct ticket* temp=head;
	bool shift_c;
	vector<int>*temp1;
	map<string,pair<int,int>>*temp_seat;
	if(train_id==1)
	{
		temp=temp->left;
		shift_c=true;
		
	}
	else if(train_id==2)
	{
		temp=temp->right;
		shift_c=false;
	}	
		while(temp!=NULL)
		{
			if(temp->ticket_no==num)
			{
				if(temp->pointer->get_passenger_count()==1)
				{
					temp->pointer->decrease_passenger_count();
					temp1=temp->pointer->get_station();
					temp_seat=temp->pointer->get_seat_holder_map();
					for(auto it:*temp_seat)
					{
						if (it.second.first == start && it.second.second == end && it.first == id) {
                        auto it1 = temp1->begin();
                        while (it1 != temp1->end()) {
                            if (*it1 >= start && *it1 < end) {
                                it1 = temp1->erase(it1);
                            } else {
                                ++it1;
								}
							}
						}
					}
					break;
				}
			}
			if(shift_c) temp=temp->left;
			else temp=temp->right;
		}
	
	
	if(category=="A/C_SLEEPER")
	{
		user_obj->add_money(300);
		
	}
	else if(category=="SLEEPER")
	{
		user_obj->add_money(200);
	}
	else
	{
		user_obj->add_money(100);
	}
}




void ticket_confirmation(Booking* obj,int booking_no,string day,string category,string bed_type,int count,int train_id,int start,int end )
{
	struct ticket * temp=nullptr;
	bool ch_t;
	if(train_id==1)
	{
		temp=head->left;
		ch_t=true;
	}
	else if (train_id==2)
	{
		temp=head->right;
		ch_t=false;
	}
		while(count)
		{
			
			while(temp!=NULL)
			{
				if(temp->day==day && temp->pointer->get_category()==category && temp->pointer->get_bed_type()==bed_type)
				{
					map<string,pair<int,int>>* temp_map;
					temp_map=temp->pointer->get_seat_holder_map();
					vector<int>*temp1=temp->pointer->get_station();
					if(temp_map->empty())
					{
							temp->pointer->set_status("FULL");
							temp->pointer->increase_passenger_count();
							obj->insert_map_values(temp->pointer->get_ticket_no(),category,bed_type);
							temp->pointer->insert_seat_holder_map(current_user_id,start,end);
							for(int i=start;i<end;i++)
							{
								temp1->push_back(i);
							}
							break;
					}	
					else if(!temp_map->empty())
					{
						bool j;
						for(int i=start;i<end;i++)
						{
							auto it=find(temp1->begin(),temp1->end(),i);
							if(it!=temp1->end())
							{
								j=true;
								break;
							}
							else
							{
								j=false;
								
							}
						}
						if(!j)
						{
							temp->pointer->set_status("FULL");
							temp->pointer->increase_passenger_count();
							obj->insert_map_values(temp->pointer->get_ticket_no(),category,bed_type);
							temp->pointer->insert_seat_holder_map(current_user_id,start,end);
							for(int i=start;i<end;i++)
							{
								temp1->push_back(i);
							}
							break;	
						}
						}
					}		
				 	
					if(ch_t) temp=temp->left;
					else temp=temp->right;
				}
				count--;                                                                                               	
		}
		return;
}


bool ticket_count_checker(string day,string category, string bed_type,int count,int start,int end,int train_id)
{
	struct ticket * temp=nullptr;
	bool c_h;
	int seat_count=0;
	if(train_id==1)
	{
		temp=head->left;
		c_h=true;
	}
	else if(train_id=2)
	{
		temp=head->right;
		c_h=false;
	}
			
			while(temp!=NULL)
			{
				if(temp->day==day && temp->pointer->get_category()==category && temp->pointer->get_bed_type()==bed_type)
				{
					map<string,pair<int,int>>* temp_map;
					temp_map=temp->pointer->get_seat_holder_map();
					vector<int>*temp1=temp->pointer->get_station();
					if(temp_map->empty())	
					{
						seat_count++;
							
					}
						
					else if(!temp_map->empty())
					{
						bool j;
						for(int i=start;i<end;i++)
						{
							auto it=find(temp1->begin(),temp1->end(),i);
							if(it!=temp1->end())
							{
								j=true;
								break;
							}
							else
							{
								j=false;
								
							}
						}
						if(!j)
						{
							seat_count++;	
						}
						}
					}
							
					if(c_h) temp=temp->left;
					else if(!c_h) temp=temp->right;
					if (seat_count>=count)
					{
						return true;
					}
				}
			if (seat_count<=count)
			{
				return false;
			}
	return false;
}
void show_train_route(int train_id)
{
	if(train_id==1)
	{
		
		cout<<"\tWELCOME TO YAMUNA EXPRESS"<<endl;
		cout<<"SOURCE : CHENNAI         DESTINATION : TRICHY"<<endl;
		cout<<"STATIONS:"<<endl;
		cout<<"1.CHENNAI"<<endl;
		cout<<"2.CHENGALPATTU"<<endl;
		cout<<"3.ARIYALUR"<<endl;
		cout<<"4.TRICHY"<<endl;
	}
	else if(train_id==2)
	{
		cout<<"\tWELCOME TO CAUVERY EXPRESS"<<endl;
		cout<<"SOURCE : TRICHY         DESTINATION : RAMNATHAPURAM"<<endl;
		cout<<"STATIONS:"<<endl;
		cout<<"1.TRICHY"<<endl;
		cout<<"2.DEVAKOTTAI"<<endl;
		cout<<"3.MANAMADURAI"<<endl;
		cout<<"4.RAMNATHAPURAM"<<endl;
		
	}
}
void ticket_booking(User* user_obj)
{
	string answer;
	bool senior_citizen=false;
	if(current_user_age>50)
	{
		senior_citizen=true;
	}
	int seat;
	int total;
	int booking_no=rand() % 100 + 1;
	string day,category,bed_type,bed1,bed2,bed3,cat1,cat2,cat3;
	int cat,count,count1,count2,count3,route,train_id,start,end;
	label:
	cout<<"1.YAMUNA EXPRESS"<<endl;
	cout<<"2.CAUVERY EXPRESS"<<endl;
	cout<<"SELECT A TRAIN TO BOOK TICKET :"<<endl;
	cin>>train_id;
	show_train_route(train_id);
	cin.clear();
	cout<<"SELECT THE STATION NUMBER YOU WANT TO BOARD AT :"<<endl;
	cin>>start;
	if(start>3 ||start <=0)
	{
		cout<<"INCORRECT INPUT!!!!"<<endl;
		goto label;
	}
	cout<<"SELECT THE STATION NUMBER YOU WANT TO ARRIVE AT :"<<endl;
	cin>>end;
	cin.clear();
	if (end==1 ||end <=0 ||end<start)
	{
			cout<<"INCORRECT INPUT!!!!"<<endl;
			goto label;
	}
	
	
	cout<<"PLEASE ENTER THE DAY IN WHICH YOU WANT TO BOOK TICKET:"<<endl;
	cin>>day;
	
	cout<<"\t HERE ARE THE CATEGORIES OF TICKETS :"<<endl;
	cout<<"A/C_SLEEPER"<<endl<<"SLEEPER"<<endl<<"SITTER"<<endl;
	cout<<"IF YOU WANT TO BOOK TICKETS IN MORE THAN ONE CATEGORY PRESS 1 OR ELSE 0:"<<endl;
	cin>>cat;
	if(cat)
	{
		cout<<"DO YOU WANT TO BOOK TICKETS IN A/C_SLEEPER CATEGORY IF YES PRESS 1 OR ELSE 0:"<<endl;
		int output1;
		cin>>output1;
		if (output1)
		{
			category="A/C_SLEEPER";
			int seat=300;
			if(senior_citizen)
			{
				seat=270;
			}
			cout<<"THESE ARE ALL THE AVAILABLE BED TYPES:"<<endl;
			cout<<"LOWER"<<endl<<"MIDDLE"<<endl<<"UPPER"<<endl;
			cout<<"IF YOU WANT TO BOOK TICKETS IN MORE THAN ONE BED TYPE PRESS 1 OR ELSE 0:"<<endl;
			int num;
			cin>>num;
			if(num)
			{
				cout<<"HOW MANY SEATS DO YOU WANT IN LOWER BERTH:"<<endl;
				int lower;
				cin>>lower;
				total=seat*lower;
				if(total>current_user_balance)
				{
					cout<<"INSUFFICIENT BALANCE!!!!"<<endl;
					cout<<"PRESS 1 TO UPDATE WALLET OR ANY OTHER KEY TO GO TO HOME PAGE :"<<endl;
					string answer;
					cin>>answer;
					if(answer[0]=='1')
					{
						user_obj->add_money(1000);
						goto label;
					}
					else
					{
						return;
					}	
				}
				
				else
				{
					user_obj->wallet_deduction(total);
					
				}
				//string day,string category, string bed_type,int count
				bool condition=ticket_count_checker(day,"A/C_SLEEPER","LOWER",lower,start,end,train_id);
				if(condition)
				{
					Booking *booking_obj=new Booking(booking_no,current_user_id,day,train_id,start,end);
					ticket_map.insert(make_pair(current_user_id,booking_obj));
					ticket_confirmation(booking_obj,booking_no,day,category,"LOWER",lower,train_id,start,end);
				}
				cout<<"HOW MANY SEATS DO YOU WANT IN MIDDLE BERTH:"<<endl;
				int middle;
				cin>>middle;
				total=seat*middle;
				if(total>current_user_balance)
				{
					cout<<"INSUFFICIENT BALANCE!!!!"<<endl;
					cout<<"PRESS 1 TO UPDATE WALLET OR ANY OTHER KEY TO GO TO HOME PAGE :"<<endl;
					string answer;
					cin>>answer;
					if(answer[0]=='1')
					{
						user_obj->add_money(1000);
						goto label;
					}
					else
					{
						return;
					}	
				}
				
				else
				{
					user_obj->wallet_deduction(total);
					
				}
				bool condition1=ticket_count_checker(day,"A/C_SLEEPER","MIDDLE",middle,start,end,train_id);
				if(condition1)
				{
					Booking *booking_obj=new Booking(booking_no,current_user_id,day,train_id,start,end);
					ticket_map.insert(make_pair(current_user_id,booking_obj));
					
					ticket_confirmation(booking_obj,booking_no,day,category,"MIDDLE",middle,train_id,start,end);
				}
				cout<<"HOW MANY SEATS DO YOU WANT IN UPPER BERTH:"<<endl;
				int upper;
				cin>>upper;
				total=seat*upper;
				if(total>current_user_balance)
				{
					cout<<"INSUFFICIENT BALANCE!!!!"<<endl;
					cout<<"PRESS 1 TO UPDATE WALLET OR ANY OTHER KEY TO GO TO HOME PAGE :"<<endl;
					string answer;
					cin>>answer;
					if(answer[0]=='1')
					{
						user_obj->add_money(1000);
						goto label;
					}
					else
					{
						return;
					}	
				}
				else
				{
					user_obj->wallet_deduction(total);
					
				}
				bool condition2=ticket_count_checker(day,"A/C_SLEEPER","UPPER",upper,start,end,train_id);
				if(condition2)
				{
					Booking *booking_obj=new Booking(booking_no,current_user_id,day,train_id,start,end);
					ticket_map.insert(make_pair(current_user_id,booking_obj));
					ticket_confirmation(booking_obj,booking_no,day,category,"UPPER",upper,train_id,start,end);
				}
			}
			else
			{
				cout<<"PLEASE ENTER THE BED TYPE WHICH YOU WANT TO BOOK TICKET:"<<endl;
				cin>>bed_type;
				cout<<"PLEASE ENTER THE NUMBER OF TICKETS YOU WANT TO BOOK:"<<endl;
				cin>>count;
				total=seat*count;
				if(total>current_user_balance)
				{
					cout<<"INSUFFICIENT BALANCE!!!!"<<endl;
					cout<<"PRESS 1 TO UPDATE WALLET OR ANY OTHER KEY TO GO TO HOME PAGE :"<<endl;
					string answer;
					cin>>answer;
					if(answer[0]=='1')
					{
						user_obj->add_money(1000);
						goto label;
					}
					else
					{
						return;
					}	
				}
				else
				{
					user_obj->wallet_deduction(total);
					
				}
				bool condition=ticket_count_checker(day,"A/C_SLEEPER",bed_type,count,start,end,train_id);
				if(condition)
				{
					Booking *booking_obj=new Booking(booking_no,current_user_id,day,train_id,start,end);
					ticket_map.insert(make_pair(current_user_id,booking_obj));
					ticket_confirmation(booking_obj,booking_no,day,category,bed_type,count,train_id,start,end);
				}
			}
		}
		cout<<"DO YOU WANT TO BOOK TICKETS IN SLEEPER CATEGORY IF YES PRESS 1 OR ELSE 0:"<<endl;
		int output2;
		cin>>output2;
		if(output2)
		{
			category="SLEEPER";
			int seat=200;
			if(senior_citizen)
			{
				seat=180;
			}
			cout<<"THESE ARE ALL THE AVAILABLE BED TYPES:"<<endl;
			cout<<"LOWER"<<endl<<"MIDDLE"<<endl<<"UPPER"<<endl;
			cout<<"IF YOU WANT TO BOOK TICKETS IN MORE THAN ONE BED TYPE PRESS 1 OR ELSE 0:"<<endl;
			int num;
			cin>>num;
			if(num)
			{
				cout<<"HOW MANY SEATS DO YOU WANT IN LOWER BERTH:"<<endl;
				int lower;
				cin>>lower;
				total=seat*lower;
				if(total>current_user_balance)
				{
					cout<<"INSUFFICIENT BALANCE!!!!"<<endl;
					cout<<"PRESS 1 TO UPDATE WALLET OR ANY OTHER KEY TO GO TO HOME PAGE :"<<endl;
					string answer;
					cin>>answer;
					if(answer[0]=='1')
					{
						user_obj->add_money(1000);
						goto label;
					}
					else
					{
						return;
					}	
				}
				else
				{
					user_obj->wallet_deduction(total);
					
				}
				bool condition=ticket_count_checker(day,category,"LOWER",lower,start,end,train_id);
				if(condition)
				{
					Booking *booking_obj=new Booking(booking_no,current_user_id,day,train_id,start,end);
					ticket_map.insert(make_pair(current_user_id,booking_obj));
					ticket_confirmation(booking_obj,booking_no,day,category,"LOWER",lower,train_id,start,end);
				}
				cout<<"HOW MANY SEATS DO YOU WANT IN MIDDLE BERTH:"<<endl;
				int middle;
				cin>>middle;
				total=seat*middle;
				if (total>current_user_balance)
				{
					cout<<"INSUFFICIENT BALANCE!!!!"<<endl;
					cout<<"PRESS 1 TO UPDATE WALLET OR ANY OTHER KEY TO GO TO HOME PAGE :"<<endl;
					string answer;
					cin>>answer;
					if(answer[0]=='1')
					{
						user_obj->add_money(1000);
						goto label;
					}
					else
					{
						return;
					}
				}
					
				
				else
				{
					user_obj->wallet_deduction(total);
					
				}
				bool condition1=ticket_count_checker(day,category,"MIDDLE",middle,start,end,train_id);
				if(condition1)
				{
					Booking *booking_obj=new Booking(booking_no,current_user_id,day,train_id,start,end);
					ticket_map.insert(make_pair(current_user_id,booking_obj));
					
					ticket_confirmation(booking_obj,booking_no,day,category,"MIDDLE",middle,train_id,start,end);
				}
				cout<<"HOW MANY SEATS DO YOU WANT IN UPPER BERTH:"<<endl;
				int upper;
				cin>>upper;
				total=seat*upper;
				if(total>current_user_balance)
				{
					cout<<"INSUFFICIENT BALANCE!!!!"<<endl;
					cout<<"PRESS 1 TO UPDATE WALLET OR ANY OTHER KEY TO GO TO HOME PAGE :"<<endl;
					string answer;
					cin>>answer;
					if(answer[100]=='1')
					{
						user_obj->add_money(1000);
						goto label;
					}
					else
					{
						return;
					}	
				}
				else
				{
					user_obj->wallet_deduction(total);
					
				}
				bool condition2=ticket_count_checker(day,category,"UPPER",upper,start,end,train_id);
				if(condition2)
				{
					Booking *booking_obj=new Booking(booking_no,current_user_id,day,train_id,start,end);
					ticket_map.insert(make_pair(current_user_id,booking_obj));
					ticket_confirmation(booking_obj,booking_no,day,category,"UPPER",upper,train_id,start,end);
				}
			}
			else
			{
				cout<<"PLEASE ENTER THE BED TYPE WHICH YOU WANT TO BOOK TICKET:"<<endl;
				cin>>bed_type;
				cout<<"PLEASE ENTER THE NUMBER OF TICKETS YOU WANT TO BOOK:"<<endl;
				int count;
				cin>>count;
				total=seat*count;
				if(total>current_user_balance)
				{
					cout<<"INSUFFICIENT BALANCE!!!!"<<endl;
					cout<<"PRESS 1 TO UPDATE WALLET OR ANY OTHER KEY TO GO TO HOME PAGE :"<<endl;
					string answer;
					cin>>answer;
					if(answer[0]=='1')
					{
						user_obj->add_money(1000);
						goto label;
					}
					else
					{
						return;
					}	
				}
				else
				{
					user_obj->wallet_deduction(total);
					
				}
				bool condition=ticket_count_checker(day,category,bed_type,count,start,end,train_id);
				if(condition)
				{
					Booking *booking_obj=new Booking(booking_no,current_user_id,day,train_id,start,end);
					ticket_map.insert(make_pair(current_user_id,booking_obj));
					ticket_confirmation(booking_obj,booking_no,day,category,bed_type,count,train_id,start,end);
				}
			}
		}
		std :: cout<<"DO YOU WANT TO BOOK TICKETS IN SITTER CATEGORY IF YES PRESS 1 OR ELSE 0:"<<endl;
		int output3;
		cin>>output3;
		int seat=100;
		if(senior_citizen)
		{
			seat=90;
		}
		if(output3)
		{
			cout<<"PLEASE ENTER THE NUMBER OF TICKETS YOU WANT TO BOOK:"<<endl;
			int count;
			cin>>count;
			total=seat*count;
			if(total>current_user_balance)
			{
				cout<<"INSUFFICIENT BALANCE!!!!"<<endl;
				cout<<"PRESS 1 TO UPDATE WALLET OR ANY OTHER KEY TO GO TO HOME PAGE :"<<endl;
				string answer;
				cin>>answer;
				if(answer[0]=='1')
				{
					user_obj->add_money(1000);
					goto label;
				}
				else
				{
					return;
				}	
			}
			else
			{
				user_obj->wallet_deduction(total);			
			}
			bool condition=ticket_count_checker(day,"SITTER","NA",count,start,end,train_id);
			if(condition)
			{
				Booking *booking_obj=new Booking(booking_no,current_user_id,day,train_id,start,end);
				ticket_map.insert(make_pair(current_user_id,booking_obj));
				
				ticket_confirmation(booking_obj,booking_no,day,"SITTER","NA",count,train_id,start,end);
			}
		}
	}
	else
	{
		cout<<"PLEASE ENTER THE CATEGORY IN WHICH YOU WANT TO BOOK TICKET:"<<endl;
		cin>>category;
		if(category=="A/C_SLEEPER" ||category=="SLEEPER")
		{
			int seat=0;
			if (category=="A/C_SLEEPER")
			{
				seat=300;
				if(senior_citizen)
				{
					seat=270;
				}
			}
			else
			{
				
				int seat=200;
				if(senior_citizen)
				{
					seat=180;
				}
			}
			cout<<"THESE ARE ALL THE AVAILABLE BED TYPES:"<<endl;
			cout<<"LOWER"<<endl<<"MIDDLE"<<endl<<"UPPER"<<endl;
			cout<<"IF YOU WANT TO BOOK TICKETS IN MORE THAN ONE BED TYPE PRESS 1 OR ELSE 0:"<<endl;
			int num;
			cin>>num;
			if(num)
			{
				cout<<"HOW MANY SEATS DO YOU WANT IN LOWER BERTH:"<<end;
				int lower;
				cin>>lower;
				total=seat*lower;
				if(total>current_user_balance)
				{
					cout<<"INSUFFICIENT BALANCE!!!!"<<endl;
					cout<<"PRESS 1 TO UPDATE WALLET OR ANY OTHER KEY TO GO TO HOME PAGE :"<<endl;
					string answer;
					cin>>answer;
					if(answer[0]=='1')
					{
						user_obj->add_money(1000);
						goto label;
					}
					else
					{
						return;
					}
						
				}
				else
				{
					user_obj->wallet_deduction(total);
					
				}
				bool condition=ticket_count_checker(day,category,"LOWER",lower,start,end,train_id);
				if(condition)
				{
					Booking *booking_obj=new Booking(booking_no,current_user_id,day,train_id,start,end);
					ticket_map.insert(make_pair(current_user_id,booking_obj));
					ticket_confirmation(booking_obj,booking_no,day,category,"LOWER",lower,train_id,start,end);
				}
				cout<<"HOW MANY SEATS DO YOU WANT IN MIDDLE BERTH:"<<endl;
				int middle;
				cin>>middle;
				total=seat*middle;
				if(total>current_user_balance)
				{
					cout<<"INSUFFICIENT BALANCE!!!!"<<endl;
					cout<<"PRESS 1 TO UPDATE WALLET OR ANY OTHER KEY TO GO TO HOME PAGE :"<<endl;
					cin>>answer;
					if(answer[0]=='1')
					{
						user_obj->add_money(1000);
						goto label;
					}
					else
					{
						return;
					}	
				}
				else
				{
					user_obj->wallet_deduction(total);
					
				}
				bool condition1=ticket_count_checker(day,category,"MIDDLE",middle,start,end,train_id);
				if(condition1)
				{
					Booking *booking_obj=new Booking(booking_no,current_user_id,day,train_id,start,end);
					ticket_map.insert(make_pair(current_user_id,booking_obj));
					ticket_confirmation(booking_obj,booking_no,day,category,"MIDDLE",middle,train_id,start,end);
				}
				cout<<"HOW MANY SEATS DO YOU WANT IN UPPER BERTH:"<<endl;
				int upper;
				cin>>upper;
				total=seat*upper;
				if(total>current_user_balance)
				{
					cout<<"INSUFFICIENT BALANCE!!!!"<<endl;
					cout<<"PRESS 1 TO UPDATE WALLET OR ANY OTHER KEY TO GO TO HOME PAGE :"<<endl;
					string answer;
					cin>>answer;
					if(answer[0]=='1')
					{
						user_obj->add_money(1000);
						goto label;
					}
					else
					{
						return;
					}	
				}
				else
				{
					user_obj->wallet_deduction(total);
					
				}
				bool condition2=ticket_count_checker(day,category,"UPPER",upper,start,end,train_id);
				if(condition2)
				{
					Booking *booking_obj=new Booking(booking_no,current_user_id,day,train_id,start,end);
					ticket_map.insert(make_pair(current_user_id,booking_obj));
					ticket_confirmation(booking_obj,booking_no,day,category,"UPPER",upper,train_id,start,end);
				}
				
			}
			else
			{
				cout<<"PLEASE ENTER THE BED TYPE WHICH YOU WANT TO BOOK TICKET:"<<endl;
				cin>>bed_type;
				cout<<"PLEASE ENTER THE NUMBER OF TICKETS YOU WANT TO BOOK:"<<endl;
				
				cin>>count;
				total=seat*count;
				if(total>current_user_balance)
				{
					cout<<"INSUFFICIENT BALANCE!!!!"<<endl;
					cout<<"PRESS 1 TO UPDATE WALLET OR ANY OTHER KEY TO GO TO HOME PAGE :"<<endl;
					string answer;
					cin>>answer;
					if(answer[0]=='1')
					{
						user_obj->add_money(1000);
						goto label;
					}
					else
					{
						return;
					}	
				}
				else
				{
					user_obj->wallet_deduction(total);
					
				}
				bool condition=ticket_count_checker(day,category,bed_type,count,start,end,train_id);
				if(condition)
				{
					Booking *booking_obj=new Booking(booking_no,current_user_id,day,train_id,start,end);
					ticket_map.insert(make_pair(current_user_id,booking_obj));
					ticket_confirmation(booking_obj,booking_no,day,category,bed_type,count,train_id,start,end);
				}
			}
		}
		else
		{
			int seat=100;
			if(senior_citizen)
			{
				seat=90;
			}
			bed_type="NA";
			cout<<"PLEASE ENTER THE NUMBER OF TICKETS YOU WANT TO BOOK:"<<end;
			cin>>count;
			total=seat* count;
			current_user_balance=user_obj->get_wallet_amount();
			if(total>current_user_balance)
			{
				cout<<"INSUFFICIENT BALANCE!!!!"<<endl;
				cout<<"PRESS 1 TO UPDATE WALLET OR ANY OTHER KEY TO GO TO HOME PAGE :"<<endl;
				cin>>answer;
				if(answer[100]=='1')
				{
					user_obj->add_money(1000);
					user_obj->add_money(1000);
					goto label;
				}
				else
				{
					return;
				}	
			}
			else
			{
				user_obj->wallet_deduction(total);			
			}
			bool condition=ticket_count_checker(day,"SITTER","NA",count,start,end,train_id);
			if(condition)
			{
				cout<<booking_no<<endl;
				cout<<current_user_id<<endl;
				Booking *booking_obj=new Booking(booking_no,current_user_id,day,train_id,start,end);
				ticket_map.insert(make_pair(current_user_id,booking_obj));
				ticket_confirmation(booking_obj,booking_no,day,category,bed_type,count,train_id,start,end);
			}
		}
	}

}





void booked_tickets(string user_id)
{
	cout<<"| BOOKING_ID | TICKET_NO | CATEGORY | BED_TYPE |"<<endl;
	cout<<"------------------------------------------------"<<endl;
	for(auto it:ticket_map)
	{
		if(it.first==user_id)
		{
			
			map<int,pair<string,string>> result=it.second->get_map();
			for(auto ite : result)
			{
				cout<<"|    "<<it.second->get_booking_id()<<"    |    "<<ite.first<<"   | "<<ite.second.first<<" |  "<<ite.second.second<<"   |"<<endl;
			}
		}
	}
	cout<<"------------------------------------------------"<<endl;

}



void reshedule_ticket(User *user_obj)
{
	bool exists=user_history(user_obj->get_user_id());
	if(!exists)
	{
		cout<<"!!!NO TICKETS HAS BEEN BOOKED TO CANCEL!!!"<<endl;
		return;
	}
	cancel_ticket(user_obj);
	
	cout<<"ReBooking the ticket give the info:"<<endl;	
	string day,category,bed_type;
	int start,end,train_id,seat,total;	
	label:
	cout<<"1.YAMUNA EXPRESS"<<endl;
	cout<<"2.CAUVERY EXPRESS"<<endl;
	cout<<"SELECT A TRAIN TO BOOK TICKET :"<<endl;
	cin>>train_id;
	show_train_route(train_id);
	cin.clear();
	cout<<"SELECT THE STATION NUMBER YOU WANT TO BOARD AT :"<<endl;
	cin>>start;
	if(start>3 ||start <=0)
	{
		cout<<"INCORRECT INPUT!!!!"<<endl;
		goto label;
	}
	cout<<"SELECT THE STATION NUMBER YOU WANT TO ARRIVE AT :"<<endl;
	cin>>end;
	cin.clear();
	if (end==1 ||end <=0 ||end<start)
	{
			cout<<"INCORRECT INPUT!!!!"<<endl;
			goto label;
	}
					
	cout<<"Enter the day: "<<endl;
	cin>>day;
	label_rt:
	cout<<"A/C_SLEEPER"<<endl<<"SLEEPER"<<endl<<"SITTER"<<endl;
	cout<<"enter the category:"<<endl;
	cin>>category;
	cout<<"enter the bed type: ";
	cin>>bed_type;
	cout<<"enter the source: "<<endl;
	cin>>start;
	cout<<"enter the destination: "<<endl;
	cin>>end;
					
	if(category=="A/C_SLEEPER") seat=300;
	else if(category=="SLEEPER") seat=200;
	else if(category=="SITTER") seat=100;
	else 
	{
		cout<<"enter the correct info"<<endl;
		goto label_rt;
	}
	total=seat*1;
	if(total>current_user_balance)
	{
		cout<<"INSUFFICIENT BALANCE!!!!"<<endl;
		cout<<"PRESS 1 TO UPDATE WALLET OR ANY OTHER KEY TO GO TO HOME PAGE :"<<endl;
		string answer;
		cin>>answer;
					
		if(answer[0]=='1')
		{
			user_obj->add_money(1000);
			goto label;
		}
		else
		{
			return;
		}	
	}
	else
	{
		user_obj->wallet_deduction(total);
					
	}
				
	bool condition2=ticket_count_checker(day,category,bed_type,1,start,end,train_id);
	if(condition2)
	{
		int booking_no=rand() % 100 + 1;
		Booking *booking_obj=new Booking(booking_no,current_user_id,day,train_id,start,end);
		ticket_map.insert(make_pair(current_user_id,booking_obj));
		ticket_confirmation(booking_obj,booking_no,day,category,bed_type,1,train_id,start,end);
	}
}
void main_log_in(Node * root)
{
	User* user_obj = log_in();
	cout<<root<<endl;
	if (user_obj==NULL)
	{
		return;
	}
	current_user_id=user_obj->get_user_id();
	
	current_user_balance=user_obj->get_wallet_amount();
	cout<<"BALANCE IS : "<<current_user_balance<<endl;
	if(current_user_id=="NULL")
	{
		cout<<"\t!!!!LOGIN FAILED"<<endl;
	}
	else
	{
		bool exit1=true;
		do
		{
			cout<<endl;
			cout<<left;
			cout<<"SELECT AN OPTION:"<<endl;
			cout<<setw(10)<<"1"<<setw(10)<<"-"<<"BOOK TICKETS"<<endl;
			cout<<setw(10)<<"2"<<setw(10)<<"-"<<"TICKET AVAILABLE DAYS"<<endl;
			cout<<setw(10)<<"3"<<setw(10)<<"-"<<"VIEW AVAILABLE TICKETS"<<endl;
			cout<<setw(10)<<"4"<<setw(10)<<"-"<<"VIEW TICKET DETAILS"<<endl;
			cout<<setw(10)<<"5"<<setw(10)<<"-"<<"USER HISTORY"<<endl;
			cout<<setw(10)<<"6"<<setw(10)<<"-"<<"CANCEL TICKET"<<endl;
			cout<<setw(10)<<"7"<<setw(10)<<"-"<<"CHECK WALLET BALANCE"<<endl;
			cout<<setw(10)<<"8"<<setw(10)<<"-"<<"UPDATE WALLET BALANCE"<<endl;
			cout<<setw(10)<<"9"<<setw(10)<<"-"<<"RESHEDULE TICKET"<<endl;
		  cout<<setw(10)<<"10"<<setw(10)<<"-"<<"EXIT"<<endl;
		  cout<<endl;
		    int opt;
		    cin>>opt;
			switch(opt)
			{	
				case 1:
					ticket_booking(user_obj);
					break;
				case 2:
					cout<<"SUNDAY"<<endl<<"MONDAY"<<endl<<"TUESDAY"<<endl<<"WEDNESDAY"<<endl<<"THURSDAY"<<endl<<"FRIDAY"<<endl<<"SATURDAY"<<endl;
					break;
				case 3:
					available_tickets(head);
					break;
				case 4:
					ticket_details();
					break;
				case 5:
					user_history(current_user_id);
					break;
				case 6:	
					cancel_ticket(user_obj);
					break;
				case 7:
					user_obj->get_wallet_amount();
					break;
				case 8:
					{
					int amount;
					cout<<"enter the amount:";
					cin>>amount;
					user_obj->add_money(amount);
					}
					break;
				case 9:
					reshedule_ticket(user_obj);
					break;
				case 10:
					exit1=false;
					break;
			}
		}while(exit1);
	}
}



