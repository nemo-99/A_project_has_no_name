#include<iostream>
#include<string.h>
#include<fstream>

using namespace std;
class node
{
public:
  node* next;
  int age;
  string password;
  string name;

  void get_user() //to read about eception HANDLING
  {
    cout<<"\nEnter your name:\n";
    cin.ignore();
    getline(cin,name);
    cout<<"\nEnter your age : ";
    cin>>age;
    cout<<"\nEnter your password :";
    cin>>password;
    cout<<"\n\nThe account is created successfully\n";
  }

  node()
  {
    next=NULL;
  }
};


class client
{
 // int last_id;

  node *head[26];
public:
  client()
  {
      for(int i = 0;i < 26;i++)
      {
          head[i] = NULL;
      }
  }
  //getnode();
  upload();
  download();

};

client :: upload()
{
    fstream f;
    f.open("users.DAT",ios::in);
    for(int i = 0;i< 26;i++)
    {
        node *temp = head[i];
        while(temp != NULL)
        {
            f.write((char *) temp , sizeof(node));
            temp = temp->next;
        }

    }

}


int main()
{

  client c;

  return 0;
}
