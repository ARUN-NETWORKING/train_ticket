#ifndef Ticket_cpp
#define Ticket_cpp
#include<main.h>
#include <stdlib.h>
#include<algorithm>




void particular_ticket_details(struct ticket * head,string d, int n,int id)
{
	struct  ticket *temp=nullptr;
	cout<<"| TICKET_NO | CATEGORY | BED_TYPE | STATUS | FARE |"<<endl;
	cout<<"---------------------------------------------------"<<endl;
	if(id==1)
	{
		temp=head->left;
		while(temp!=NULL)
		{
			if(temp->day==d && temp->ticket_no==n)
			{
				cout<<"|    "<<temp->ticket_no<<"   | "<<temp->pointer->get_category()<<"  |  "<<temp->pointer->get_bed_type()<<"   |  "
				<<temp->pointer->get_status()<<"  |  "<<temp->pointer->get_fare()<<" |"<<endl;
			}
		temp=temp->left;
		}
	}
	else
	{
		temp=head->right;
		while(temp!=NULL)
		{
			if(temp->day==d && temp->ticket_no==n)
			{
				cout<<"|    "<<temp->ticket_no<<"   | "<<temp->pointer->get_category()<<"  |  "<<temp->pointer->get_bed_type()<<"   |  "<<temp->pointer->get_status()<<"  |  "<<temp->pointer->get_fare()<<" |"<<endl;
			}
			temp=temp->right;
		}
	}
	
	
	cout<<"---------------------------------------------------"<<endl;
}

void show_ticket(struct  ticket *head, string day,string category,int id, string bed_type,int start,int end,int train_id)
{
	struct  ticket *temp=nullptr;
	cout<<"| TICKET_NO | CATEGORY | BED_TYPE | FARE |"<<endl;
	cout<<"---------------------------------------------------"<<endl;
	bool c_h;
	int seat_count=0;
	if(train_id==1)
	{
		temp=head->left;
		c_h=true;
	}
	else if(train_id==2)
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
						cout<<"|    "<<temp->ticket_no<<"   | "<<temp->pointer->get_category()<<"  |  "<<temp->pointer->get_bed_type()<<"   |  "<<temp->pointer->get_status()<<"  |  "<<temp->pointer->get_fare()<<" |"<<endl;
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
							
						cout<<"|    "<<temp->ticket_no<<"   | "<<temp->pointer->get_category()<<"  |  "<<temp->pointer->get_bed_type()<<"   |  "<<temp->pointer->get_status()<<"  |  "<<temp->pointer->get_fare()<<" |"<<endl;
					
						}
					}
				}
					
					if(c_h) temp=temp->left;
					else if(!c_h) temp=temp->right;
				}
		
	cout<<"---------------------------------------------------"<<endl;
}

void available_tickets(struct ticket * head)
{
	label:
	string available_day,available_category,available_bed_type;
	int id;
	int train_id;//
	int start;//
	int end;//
	cout<<"1.YAMUNA EXPRESS"<<endl;
	cout<<"2.CAUVERY EXPRESS"<<endl;
	cout<<"ENTER THE TRAIN ID :"<<endl;
	cin>>id;
	if(id==1)
	{
		train_id=1;
		cout<<"\tWELCOME TO YAMUNA EXPRESS"<<endl;
		cout<<"SOURCE : CHENNAI         DESTINATION : TRICHY"<<endl;
		cout<<"STATIONS:"<<endl;
		cout<<"1.CHENNAI"<<endl;
		cout<<"2.CHENGALPATTU"<<endl;
		cout<<"3.ARIYALUR"<<endl;
		cout<<"4.TRICHY"<<endl;
		cout<<"SELECT THE STATION NUMBER YOU WANT TO BOARD AT :"<<endl;
		cin>>start;
		if(start>3 ||start <=0)
		{
			cout<<"INCORRECT INPUT!!!!"<<endl;
			goto label;
		}
		cout<<"SELECT THE STATION NUMBER YOU WANT TO ARRIVE AT :"<<endl;
		cin>>end;
		if(end==1 ||end <=0 ||end<start)
		{
			cout<<"INCORRECT INPUT!!!!"<<endl;
			goto label;
		}
	}
	else
	{
		id=2;
		cout<<endl;
		cout<<"\tWELCOME TO CAUVERY EXPRESS"<<endl;
		cout<<"SOURCE : TRICHY         DESTINATION : RAMNATHAPURAM"<<endl;
		cout<<"STATIONS:"<<endl;
		cout<<"1.TRICHY"<<endl;
		cout<<"2.DEVAKOTTAI"<<endl;
		cout<<"3.MANAMADURAI"<<endl;
		cout<<"4.RAMNATHAPURAM"<<endl;
		cout<<"SELECT THE STATION NUMBER YOU WANT TO BOARD AT :"<<endl;
		cin>>start;
		cout<<endl;
		if(start>3 ||start <=0)
		{
			cout<<"INCORRECT INPUT!!!!"<<endl;
			goto label;
		}
		cout<<"SELECT THE STATION NUMBER YOU WANT TO ARRIVE AT :"<<endl;
		cin>>end;
		if(end==1 ||end <=0 ||end<start)
		{
			cout<<"INCORRECT INPUT!!!!"<<endl;
			goto label;
		}
	}
	cout<<endl;
	cout<<"ENTER THE DAY IN WHICH YOU WANT TO SEE AVAILABLE TICKETS :"<<endl;
	cin>>available_day;
	cout<<"ENTER THE CATEGORY IN WHICH YOU WANT TO SEE AVAILABLE TICKETS :"<<endl;
	cin>>available_category;
	cout<<"ENTER THE BED TYPE IN WHICH YOU WANT TO SEE AVAILABLE TICKETS :"<<endl;
	cin>>available_bed_type;
	show_ticket(head,available_day,available_category,id,available_bed_type,start,end,id);
	cout<<endl;
}

void ticket_details()
{
	int num,id;
	string da;
	cout<<endl;
	cout<<"ENTER THE TRAIN ID :"<<endl;
	cin>>id;
	cout<<"ENTER THE DAY IN WHICH YOU WANT TO SEE THE DETAILS OF A PARTICULAR TICKET TICKETS :"<<endl;
	cin>>da;
	cout<<"ENTER THE TICKET NUMBER :"<<endl;
	cin>>num;
	particular_ticket_details(head,da,num,id);
	cout<<endl;

}


struct ticket * ticket_struct_creator(Ticket* ptr,string d,int t_no,int id)
{
	if(id==1)
	{
		struct ticket *temp1,*temp=(struct ticket *)malloc(sizeof(struct Ticket));
		temp->pointer=ptr;
		temp->ticket_no=t_no;
		temp->day=d;
		temp1=head;
    		temp ->left=NULL;
    	if(head==NULL){
    	    head=temp;
    	    return head;
    	}
    	else{
    	    while(temp1->left != NULL){
    	        temp1=temp1->left;
    	    }
    		temp1->left=temp;
    	}
    	return head;
	}
	else
	{
		struct ticket *temp1,*temp=(struct ticket *)malloc(sizeof(struct Ticket));
		temp->pointer=ptr;
		temp->ticket_no=t_no;
		temp->day=d;
		temp1=head;
    		temp ->right=NULL;
    	if(head==NULL)
    	{
        	head=temp;
    	}
    	else
    	{
        	while(temp1->right != NULL)
        	{
            	temp1=temp1->right;
        	}
    		temp1->right=temp;
    	}
		return head;
	}
	return head;
}

void ticket_init(string category, string bed_type , string day, int fare, int count)
{
	//creating tickets for each category
	for(int i=0;i<count;i++)
	{
		Ticket * obj=new Ticket(++ticket_no,category,bed_type,day,fare,train1_id);
		head=ticket_struct_creator(obj,day,ticket_no,train1_id);
	}
	for(int j=0;j<count;j++)
	{
		Ticket * obj=new Ticket(++ticket_no,category,bed_type,day,fare,train2_id);
		head=ticket_struct_creator(obj,day,ticket_no,train2_id);
	}
}

//giving the essential details for creating the ticket
void ticket_categories(string day)
{
	
	ticket_init("SLEEPER","LOWER",day,200,30);
	ticket_init("SLEEPER","MIDDLE",day,200,30);
	ticket_init("SLEEPER","UPPER",day,200,30);
	
	ticket_init("A/C_SLEEPER","LOWER",day,300,30);
	ticket_init("A/C_SLEEPER","MIDDLE",day,300,30);
	ticket_init("A/C_SLEEPER","UPPER",day,300,30);
	
	ticket_init("SITTER","NA",day,100,30);
	

}

struct ticket *ticket_creation()
{
	Ticket* dummy_ticket_ptr;//
	string d;//
	//
	head=new ticket(dummy_ticket_ptr,-1,d,-1);//
	ticket_no=1000;
	ticket_categories("SUNDAY");
	ticket_no=1000;
	ticket_categories("MONDAY");
	ticket_no=1000;
	ticket_categories("TUESDAY");
	ticket_no=1000;
	ticket_categories("WEDNESDAY");
	ticket_no=1000;
	ticket_categories("THURSDAY");
	ticket_no=1000;
	ticket_categories("FRIDAY");
	ticket_no=1000;
	ticket_categories("SATURDAY");
	cout<<"tick_creat:  "<<head<<endl;
	return head;
}
#endif

