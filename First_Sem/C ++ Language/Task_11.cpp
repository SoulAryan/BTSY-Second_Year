/////////////////////////////////ABSTARCT CLASS///////////////////////////////////////

#include <iostream>
using namespace std;

class shape
{
public:
      virtual void draw()=0;    
};

class circle:public shape
{
public:
      void draw()
      {
            cout<<"Drawing Circle"<<endl;
      }    
};

class rectangle : public shape
{
public: 
      void draw()
      {
           cout<<"Drawing rectangle"<<endl;
      }    
};

int main()
{
    circle c1;
    rectangle r1;

    shape *s1;
    s1=&c1;
    s1->draw();

    s1=&r1;
    s1->draw();

    return 0;
} 