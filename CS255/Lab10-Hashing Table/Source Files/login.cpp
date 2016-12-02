/*
#include <iostream>
#include <string>
#include<fstream>
#include<cstdlib>


using namespace std;

#include "HashTable.cpp"

class User
{
public:
	User();
	void setName(const string& newName);
	void setKey(const string& newPassword);
	string getName()const;
	string getKey()const; //get the password
	static unsigned int hash(const string& str);
private:
	string name; 
	string key;	//will hold the password

};

User::User(): name("EMPTY"), key("EMPTY") {}



void User::setKey(const string& newPassword)
{
	key= newPassword;

}
	
void User::setName(const string& newName)
{
	name= newName;
}

string User::getName()const
{
	return name;
}

string User::getKey()const
{
	return key;
}
unsigned int User::hash(const string& str) {
    unsigned int val = 0;
	for (int i=0; i< str.length(); i++)
		val= val + str[i];
	return val;

}


//*******************************************************


int main()
{
	HashTable <User, string> usersTable(10);
	User currentUser;
	string v1,v2;
	ifstream in;
	in.open("password.txt");
	//---------------
	// Declaration of variables need to get user name and password
	string stars="******************************************************";
	string lines="--------------------------------------------------------";
	string userN,passwordN;
	char userCommand;	//will store the user option to continue trying logging ini process

	if (in.fail() )
	{
		cout<<"An Error Has Occured While Opening the file."<<endl;
		exit(1);
	}
	
	in>>v1>>v2; //reads the first to strings off each line
	while( ! in.eof() )
	{
		currentUser.setName(v1);
		currentUser.setKey(v2);
		usersTable.insert(currentUser);
		in>>v1>>v2;
	}
	
	//---------------------------------------------------
	//Login Prompt & User/ Password Lookup
	//---------------------------------------------------
	do 
	{
		cout<<stars<<endl;
		cout<<"----- WELCOME TO THE USER LOGIN SECTION-------"<<endl<<endl;
		cout<<"Please enter the your user name: "<<endl;
		cin>>userN;
		cout<<"Now please enter you password: "<<endl;
		cin>>passwordN;

		cout<< "Obtaining login information..."<<endl<<endl;
		if ( usersTable.retrieve(passwordN,currentUser) ) //if true, then match it with username
		{
		
			if (currentUser.getName() == userN)
			{
				cout<<stars<<endl;
				cout<<"AUTHENTICATION SUCCESSFUL"<<endl;
				cout<<stars<<endl<<endl;
			}
			
	
			else 
			{
				cout<<"AUTHENTICATION FAILURE"<<endl<<endl;
				
				
			}
		}
	
		else // password does not match any key(password) in the HashTable.
		{
			cout<<"AUTHENTICATION FAILURE"<<endl<<endl;
		}
		cout<<lines<<endl;
		cout<<"Would You Like To Try Logining In Again?"<<endl;
		cout<<"Enter the character 'y' or 'Y' for yes, and 'n' or 'N' for no."<<endl;
		cin>>userCommand;
		cout<<lines<<endl;
	} while(userCommand == 'y' || userCommand == 'Y');
	in.close();
	return 0;

}*/