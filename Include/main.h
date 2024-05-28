#ifndef Main_H
#define Main_H
#include<iostream>
#include<string>
#include<map>
#include<ticket.h>
#include<booking.h>
#include<user.h>
using namespace std;

class Ticket;
struct ticket;
class User;
class Train;
struct Node;


 extern Ticket *ticket_dummy;

extern map <int ,Train *>train_map;
extern struct ticket * head;
extern User *dummy;

extern string current_user_id, current_user_gender, current_user_name;
extern int current_train_id;

extern int current_user_age;

static int current_user_balance;
static struct Node* root;

using namespace std;

void particular_ticket_details(struct ticket * head,string d, int n,int id);
void train_creation();
void show_ticket(struct  ticket *head, string day,string category,int id, string bed_type,int start,int end);
void available_tickets(struct ticket * head);
void ticket_details();
struct ticket * ticket_struct_creator(Ticket* ptr,string d,int t_no,int id);
void ticket_init(string category, string bed_type , string day, int fare, int count);
void ticket_categories(string day);
struct ticket * ticket_creation();
bool check(Node* root, string id);
User* check_password(Node* root, string pw);
User* log_in();
Node* insert(Node* root, User *pointer, string gender, string name, int age, string user_id);
void insert_logic(User *pointer,string name, string gender,  int age, string user_id);
void obj_creation(string name, string gender, string user_id, string password , int age , long int number);
void sign_up();
Node* createBinaryTree();
void user_creation(Node * root);
void main_log_in(Node* root);

#endif





