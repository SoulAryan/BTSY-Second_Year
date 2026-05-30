////////////////////Abstract Class//////////////////////
#include <iostream>
using namespace std;

class Flower
{
public:
     virtual void run()=0;    
};

class Rose : public Flower
{
public:
     void run()
     {
          cout<<"Rose is blooming"<<endl;
     }    
};

int main()
{
    Flower *f1=new Rose();
    f1->run();

    return 0;

}