#include<iostream>
#include<string>

using namespace std;

class User;

User *dummy=nullptr;

string current_user_id="NULL",current_user_gender="NULL",current_user_name="NULL",current_train_id=0;

int current_user_age=0;

static int current_user_balance;

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

static Node* root=NULL;



