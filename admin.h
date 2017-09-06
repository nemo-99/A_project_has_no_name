#ifndef ADMIN
#define ADMIN

class administrator
{
 void menu();  // to print the menu and all the stuff
 void update(); // to chnge the movie on show
 public:
  void check(); // to check the acces to the data
  list movie; 
};

struct list
{
 string movie1,movie2,movie3,movie4;
};
#endif
  
