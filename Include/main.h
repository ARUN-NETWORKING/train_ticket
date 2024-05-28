#include<iostream>
#include<string>
#include"Train.cpp"
#include"User.cpp"
#include"Ticket.cpp"
#include"Booking.cpp"
#include"utilities.cpp"

using namespace std;

void essentials()
{
	ticket_creation();
	root = createBinaryTree();
	user_creation(root);
}


