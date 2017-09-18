#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class movie_name
{
    char str[50];
    int number;
public:
    void input(char *);
    void upload();
    void download();
    void display();
    void search_replace();
};

void movie_name :: input(char *c)
{
    cout << c << endl;
    cin.getline(str,49,'\n');


}

void movie_name :: upload()
{
     int check = 0;
     number = 0;
     fstream f;
     f.open("movie.DAT",ios::out);
     while(1)
    {

       input("Enter a movie name");
       f.write((char *) this , sizeof(movie_name) );
       number++;
       cout << "Done uploading" << endl;
       cout << "Press -1 to exit" << endl;
       cin >> check;
       cin.ignore();
       if(check == -1)
           break;

    }
    f.close();
}

void movie_name :: download()
{

    fstream f("movie.DAT",ios::in);
    while( f.read((char *) this , sizeof(movie_name) ) )
    {
        cout << str << endl;
    }
    f.close();

}

void movie_name :: search_replace()
{
    movie_name m; // = new movie_name;
    input("Enter a movie to search for .");

    fstream f("movie.DAT",ios::in|ios::out);
    int i = 0;
    while( f.read((char *) &m , sizeof(movie_name) ) )
    {
       // cout << "inside search loop" << endl;
      // cout << m.str << endl;
        if( strcmp(m.str, str) == 0  )
        {

          // cout << "inside if" << endl;
           input("Enter a replacement name");
          f.seekp(-sizeof(movie_name),ios::cur);
          // cout << "pointer pos changed" << endl;
         //  int location = (i-1)*sizeof(movie_name);
           //f.seekp(location);
           f.write((char *) this , sizeof(movie_name) );// << flush;
           cout << "file modified" << endl;
           break;
        }
        cout << "outside if" << endl;
    }
    cout << "outside " << endl;
    f.close();
    //download();
}




int main()
{
    movie_name obj1;
    obj1.upload();
    obj1.download();
    obj1.search_replace();
    obj1.download();
    return 0;
}
