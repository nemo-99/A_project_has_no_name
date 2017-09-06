#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
client user;
administrator admin;

int choice;

 cout<<"\n\t\t*****welcome*****";

 cout<<"\n please select an option";
 cout<<"\n1. new user\n2.sign in\n3.administrator\n";
 cin>>choice;
 
 switch(choice)
 {
  case 1:
     user.new_user();
     break;
  case 2:
     user.login();
     break;
  case 3:
     admin.check();
     break;
  default:
    cout<<"\ninvalid choice";
 }
 
return 0;

}
