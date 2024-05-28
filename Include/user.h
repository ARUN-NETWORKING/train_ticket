#ifndef User_h
#define User_h

#include<iostream>
#include<string>

using namespace std;

class User
{
	private:
		string name;
		int age;
		long int number;
		string gender;
		string password;
		int wallet=1000;
	protected:
		string user_id;
	public:
		//constructor
		User(){}
		User( string name, string gender, string user_id, string password, int age, long int number)
		{
			this->name=name;
			this->gender=gender;
			this->user_id=user_id;
			this->password=password;
			this->age=age;
			this->number=number;
		}
		//destructor
		~User(){}
		//setters and getters
		void set_name(string name)
		{
			this ->name=name;
		}
		void set_password(string pw)
		{
			password=pw;
		}
		void set_age(int num)
		{
			age=num;
		}
		void set_number(long num)
		{
			number=num;
		}
		void add_money(int amount)
		{
			wallet+=amount;
		}
		void wallet_deduction(int amount)
		{
			wallet-=amount;
		}
		int get_wallet_amount()
		{
			cout<<"amount in the wallet is "<<wallet<<endl;
			return wallet;
		}
		string get_name()
		{
			return name;
		}
		int get_age()
		{
			return age;
		}
		long get_number()
		{
			return number;
		}
		string get_gender()
		{
			return gender;
		}
		string get_user_id()//
		{
			return user_id;
		}
		string get_password()
		{
			return password;
		}
};


struct Node {
    string gender;
    string name;
    int age;
    string user_id;
    User* pointer;
    struct Node* left;
    struct Node* right;

    Node(User *ptr, string gen, string n, int a, string id) {
        gender = gen;
        name = n;
        age = a;
        pointer=ptr;
        user_id=id;
        left = nullptr;
        right = nullptr;
    }
};





#endif
