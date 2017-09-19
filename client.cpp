#include<iostream>
#include<string.h>
#include<fstream>

using namespace std;
class node
{
public:
  node* next;
  int age;
  int id;
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
    cout<<"\n\nThe account is created succesfully\n";
  }

  node()
  {
    next=NULL;
  }
};


class client
{
  node head[26];
public:
 client()
 {
     for(int i = 0;i < 26;i++)
     {
         head[i] = NULL;
     }
}


  void download()
  {
    node *temp;
    fstream file("users.DAT");
    while( file.read((char *) temp , sizeof(node) ) )
    {
        string name=temp->name;
        int ch = ((int)name[0])-65;
        if (head[ch]==NULL)
        {
          head[ch]=temp;
          continue;
        }
        temp->next=head[ch]->next;
        head[ch]->next=temp;
    }
    file.close();
  }
void upload();
};
void client :: upload()
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
