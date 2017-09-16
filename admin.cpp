#include<iostream>
#include<fstream>
#include<string>
#include "admin.h"

 void administrator :: check()
  {
   char password[9],test[9];
   int count=0;

  fstream file;
  file.open("password.txt",ios::in);
  file.getline(password,9);
  file.close();

 do
 {
  count++;

  cout<<"\nEnter the password";
  cin>>test;

  if(strcmp(password,test)==0)
    {
     cout<<"\nThe password is correct";
     break;
    }
  else
    cout<<"\nInvalid entry";

 }while(count<3);

  if(count==3)
   cout<<"\n YOU HAVE USED YOUR THREE CHANCE";
  else
    menu();

  return;
 }

  void administrator :: menu()
  {
   cout<<"\n******** WELCOME ADMINISTRATOR ********\n\n";
  int choice;
   do
   {
    choice=0;
    cout<<"    ***** MENU ***** \n";
    cout<<"\t1.Set ticket price\n\t2.Update movies\n\t3.Booking status\n\t4.Change password\nPlease enter your choice\n";
    cin>>choice;

    switch(choice)
    {
     case 1:
        cout<<"\nticket price";
        break;
     case 2:
        cout<<"\nUpdate Movie";
        break;
     case 3:
        cout<<"\nBooking status";
        break;
     case 4:
         cout<<"\nChange password";
         break;
     default:
        cout<<"\nInvalid entry";
     }

     cout<<"\n\nDo you want to continue as administrator (1/0) \n";
     cin>>choice;
    }while(choice);


 return ;
  }

  void administrator:: display()
  {
    fstream file("movies.txt");
    string movie;
    if(!file)
    {
       cout<<"\nunable to open file\n";
    }

    while(getline(file,movie))
    {
     cout<<endl<<movie;
    }

   cout<<endl;
   
    file.close();
  }
