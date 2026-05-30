//////////////////////////////////////////////Example 1//////////////////////////////////////////////
/*#include <iostream>
using namespace std;

class Payment
{
public: 
      virtual void pay(int amount)=0;  //pure virtual function    
};

class GooglePay: public Payment
{
public:
        void pay(int amount) override
        {
            cout<<"Amount paid using GooglePay:"<<amount<<endl;
        }    
};

class Paypal:public Payment
{
public:
        void pay(int amount) override
        {
            cout<<"Amount paid using Paypal:"<<amount<<endl;
        }    

};
int main()
{
    Payment *p1;
    Payment *p2;

    GooglePay g;
    Paypal p;

    p1=&g;
    p1->pay(300);

    p2=&p;
    p2->pay(500);

    return 0;
}*/


////////////////////////////////////////////Example 2//////////////////////////////////////////////
/*#include <iostream>
using namespace std;

class Animal
{
public:
       virtual void sound()=0;    //pure virtual function    
};

class Dog:public Animal
{
public: 
      void sound() override
      {
           cout<<"Dog Barks"<<endl;
      }    
};

class Cat:public Animal
{
public:
       void sound() override
       {
            cout<<"Cat Meows"<<endl;
       }    
};

int main()
{
  Dog d;
  Cat c;
  
  Animal *a1;
  Animal *a2;

  a1=&d;
  a2=&c;

  a1->sound();
  a2->sound();

  return 0;
}*/

////////////////////////////////////////////Example 3//////////////////////////////////////////////
#include <iostream>
using namespace std;

class Shape
{
public:
      virtual void area()=0;    //pure virtual function        
};

class Square:public Shape
{
public:
      void area() override
      {
        int side;
        cout<<"Enter side of square:";
        cin>>side;

        cout<<"Area of square:"<<side*side<<endl;
      }    
};

class Triangle:public Shape
{
public:
      void area() override
      {
        int base,height;
        cout<<"Enter base and height of triangle:";
        cin>>base>>height;

        cout<<"Area of triangle:"<<0.5*base*height<<endl;
      }
};

class Circle:public Shape
{
public:
     void area() override
     {
        float radius;
        cout<<"Enter radius of circle:";
        cin>>radius;

        cout<<"Area of Circle"<<3.14*radius*radius<<endl;
     }    

};

class Rectangle:public Shape
{
public:
      void area() override
      {
        int length,breadth;
        cout<<"Enter length and breadth of rectangle:";
        cin>>length>>breadth;

        cout<<"Area of rectangle:"<<length*breadth<<endl;
      }    

};

int main()
{
    Square s;
    Triangle t;
    Circle c;
    Rectangle r;

    Shape *sh1;
    Shape *sh2;
    Shape *sh3;
    Shape *sh4;
    
    sh1=&s;
    sh2=&t;
    sh3=&c;
    sh4=&r;

    sh1->area();
    sh2->area();    
    sh3->area();
    sh4->area();

    return 0;
}