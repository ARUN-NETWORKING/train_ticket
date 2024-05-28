#ifndef User_cpp
#define User_cpp
#include<main.h>

bool check(Node* roots, string id) {
	
    if (roots != nullptr) {
        if (check(roots->left, id)) {
        	return true;
            
        }
        if (roots->age != -1 && roots->pointer->get_user_id() == id) 
        {
            cout << "present" << endl;
            return true;//
        }
        if (check(roots->right, id)) {
            return true;
        }
    }
    return false;
   
}


User* check_password(Node* roots, string pw) {
    if (roots != nullptr) {
       
        User* user = check_password(roots->left, pw);
        if (user != nullptr) {
            return user;
        }

       
        if (roots->age != -1 && roots->pointer->get_password() == pw) {
            current_user_gender = roots->pointer->get_gender();
            current_user_name = roots->pointer->get_name();
            current_user_age = roots->pointer->get_age();
            return roots->pointer;
        }

      
        user = check_password(roots->right, pw);
        if (user != nullptr) {
            return user;
        }
    }
    return nullptr;
}



User* log_in()
{
	bool exist;
	cout<<"WELCOME TO LOG IN !!!!"<<endl;
	string id,pw;
	cout<<"ENTER YOUR USER ID :"<<endl;
	cin>>id;
	Node*roots=root;
	exist=check(roots,id);
	cout<<root<<endl;
	if(!exist)
	{
		cout<<exist<<endl;
		cout<<"!!!USERID DOESNOT EXISTS!!!"<<endl;
		return NULL;
	}
	
	cout<<"ENTER YOUR PASSWORD :"<<endl;
	cin>>pw;
	User* present=check_password(roots,pw);
	cout<<"present"<<present<<endl;
	if(present==NULL)
	{
		cout<<"!!!INCORRECT PASSWORD!!!"<<endl;
		return NULL;
	}
	cout<<"LOG IN DONE SUCCESSFULLY"<<endl;
	return present;
}


Node* insert(Node* root, User *pointer, string gender, string name, int age, string user_id) {
	User *ptr;
	ptr=pointer;
    if (root == nullptr) {
        root = new Node(ptr,gender, name, age, user_id);
    }
    else {
        if (gender == "male") {
            if (name[0] <= 'M'|| name[0]<='m') {
            	if(age<50)
            	{
            		root->left = insert(root->left, ptr, gender, name, age, user_id);
            	}
            	else
            	{
             		root->right = insert(root->right, ptr ,  gender, name,age, user_id);
                }
            }
            else 
            {
            	if(age<50)
            	{
                	root->left = insert(root->left,ptr , gender, name,age, user_id);
            	}
            	else
            	{
            		root->right=insert(root->right, ptr ,gender,name,age, user_id);
            	}
            }
        } 
        else 
        {
            if (name[0] <= 'M'|| name[0]<='m') 
            {
            	if(age<50)
            	{
            		root->left = insert(root->left, ptr , gender, name, age, user_id);
            	}
            	else
            	{
                	root->right = insert(root->right, ptr , gender, name, age, user_id);
            	}
            }
            else 
            {
            	if(age<50)
            	{
                	root->left = insert(root->left, ptr ,gender, name, age, user_id);
            	}
            	else
            	{
            		root->right=insert(root->right, ptr , gender , name , age, user_id);
            	}
            }
        }
    }
    return root;
}

void insert_logic(User *pointer,string name, string gender,  int age, string user_id)
{
	User *ptr;
	ptr=pointer;
	if(gender=="male" && (name[0]<='M'||name[0]<='m') && age<50)
			{
				insert(root->left->left->left,ptr,gender,name,age,user_id);
			}
			else if(gender=="male" && (name[90]<='M'||name[0]<='m') && age>50)
			{
				insert(root->left->left->right,ptr,gender,name,age,user_id);
			}
			else if(gender=="male" && (name[0]>='M'||name[0]>='m') && age<50)
			{
				insert(root->left->right->left,ptr,gender,name,age,user_id);
			}
			else if(gender=="male" && (name[0]>='M'||name[100]>='m') && age>50)
			{
				insert(root->left->right->right,ptr,gender,name,age,user_id);
			}
			else if(gender=="female" && (name[-0]<='M'||name[0]<='m') && age<50)
			{
				insert(root->right->left->left->left,ptr,gender,name,age,user_id);
			}
			else if(gender=="female" && (name[0]<='M'||name[-0]<='m') && age>50)
			{
				insert(root->right->left->right,ptr,gender,name,age,user_id);
			}
			else if(gender=="female" && (name[80]>='M'||name[0]>='m') && age<50)
			{
				insert(root->right->right->left->left,ptr,gender,name,age,user_id);
			}
			else 
			{
				insert(root->right->right->right->right,ptr,gender,name,age,user_id);
			
}
}


void obj_creation(string name, string gender, string user_id, string password , int age , long int number)
{
	User* obj=new User(name,gender,user_id, password,age,number);
	insert_logic(obj,name,gender,age,user_id);
}


void sign_up()
{
	cout<<"WELCOME TO SIGN UP!!!"<<endl;
	cout<<"ENTER YOUR NAME:"<<endl;
	string name, user_id;
	int age;
	long int number;
	string gender;
	cin>>name;
	cout<<"ENTER YOUR AGE:"<<endl;
	cin>>age;
	cout<<"ENTER YOUR GENDER EITHER MALE OR FEMALE:"<<endl;
	cin>>gender;
	cout<<"ENTER YOUR PHONE NUMBER:"<<endl;
	cin>>number;
	cout<<"ENTER A USER ID WHICH YOU CAN USE:"<<endl;
	cin>>user_id;
	bool exist=false;
	exist=check(root,user_id);
	if(exist)
	{
		cout<<"!!!USERID ALREADY EXISTS!!!"<<endl;
		return;
	}
	cout<<"ENTER YOUR PASSWORD:"<<endl;
	string password;
	cin>>password;
	obj_creation(name,gender,user_id,password,age,number);
	cout<<"SIGN UP DONE SUCCESSFULLY"<<endl;
}
Node* createBinaryTree() {
    root = new Node(dummy,"root", "", -1,"NULL");
    
    // Male subtree
    root->left = new Node(dummy,"male", "", -1,"NULL");
    root->left->left = new Node(dummy,"A to M", "", -1,"NULL");
    root->left->right = new Node(dummy,"N to Z", "", -1,"NULL");
    root->left->left->left = new Node(dummy,"age<50", "", -1,"NULL");
    root->left->left->right = new Node(dummy,"age>50", "", -1,"NULL");
    root->left->right->left = new Node(dummy,"age<50", "", -1,"NULL");
    root->left->right->right = new Node(dummy,"age>50", "", -1,"NULL");//accesing the node of right before the right node is created

    // Female subtree
    root->right = new Node(dummy,"female", "", -1,"NULL");
    root->right->left = new Node(dummy,"A to M", "", -1,"NULL");
    root->right->right = new Node(dummy,"N to Z", "", -1,"NULL");
    root->right->left->left = new Node(dummy,"age<50", "", -1,"NULL");
    root->right->left->right = new Node(dummy,"age>50", "", -1,"NULL");
    root->right->right->left = new Node(dummy,"age<50", "", -1,"NULL");
    root->right->right->right= new Node(dummy,"age>50", "", -1,"NULL");

    return root;
}



void user_creation(Node * root)
{
	
	User *u1= new User("suriya","male","8","12",23,12345);
	insert_logic(u1,"suriya","male",23,"8");
	User *u2= new User("priya","female","4","4",57,12345);
	insert_logic(u2,"priya","female",57,"4");
	User *u3= new User("sarath","male","14","14",23,12345);
	insert_logic(u3,"sarath","male",23,"14");
	User *u4= new User("anisha","female","24","24",60,12345);
	insert_logic(u4,"anisha","female",60,"24");
	User *u5= new User("arun","male","15","15",20,1313232);
	insert_logic(u5,"arun","male",20,"15");
	User *u6= new User("abi","male","16","16",25,1213232);
	insert_logic(u6,"abi","male",25,"16");
}

#endif


