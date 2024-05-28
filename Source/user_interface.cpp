#include<iostream>

#include<main.h>


Ticket *dummy_ticket_ptr=nullptr;
struct ticket * head=nullptr;
string current_user_id="NULL",current_user_gender="NULL",current_user_name="NULL";
int current_train_id=0;
int current_user_age=0;
User *dummy=nullptr;
map <int ,Train *>train_map;

int main()
{
	
	head=ticket_creation();
	cout<<"after tick:   "<<head<<endl;
	root =createBinaryTree();
	cout<<root<<endl;
	user_creation(root);
	cout<<root<<endl;

	bool exit=true;
	int option;
	do
	{
		cout<<"SELECT AN OPTION :"<<endl;
		cout << "1.SIGN UP" << endl;
        cout << "2.LOG IN" << endl;
        cout << "3.EXIT" << endl;
        
        cin>>option;
        switch(option)
        {
        	case 1:
                cout << "Signing up..." << endl;
                sign_up();
                break;
            case 2:
                {
               
                	cout<<root<<endl;
                	main_log_in(root);
                }
                break;
            case 3:
                cout << "Exiting..." <<endl;
                exit = false;
                break;
            default:
                cout << "Invalid option. Please enter a valid option." << endl;
        }
	}while(exit);
	return 0;
}
