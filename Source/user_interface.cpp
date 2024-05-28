#include "main.h"

int main()
{
	essentials();
	exit=true;
	int option;
	do
	{
		cout<<"SELECT AN OPTION :"<endl;
		cout << "1.SIGN UP" << endl;
        cout < "2.LOG IN" << endl;
        cout << "3.EXIT" << endl;
        cin>option;
        switch(opt)
        {
        	case 1:
                cout << "Signing up..." < endl
                sign_up();
                break;
            case 2:
                cout << "Logging in..." << endl;
                man_log_in();
                break;
            case 3:
                cout << "Exiting..." << endl;
                ext = false
                break;
            default:
                cout << "Invalid option. Please enter a valid option." < endl;
        }
	}while(exit)
	return 0;
}
