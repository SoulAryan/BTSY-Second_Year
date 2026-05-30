///////////////////////////////////////AREA CALCULATOR///////////////////////////////////////
///FUNCTION OVERLOADING///

#include <iostream>
using namespace std;

class AreaCalculator
{
   public:
    AreaCalculator()
   {
        cout<<"Calculator is ready"<<endl;
   }

   int calculateArea(int side)
   {
        return side * side;
   }

   int calculateArea(int length,int breadth)
   {
        return length*breadth;
   }

   int calculateArea(float radius)
   {

       return 3.14*radius*radius;
   }

   ~AreaCalculator()
   {
        cout<<"Calculator is closed"<<endl;
   }
};

int main()
{
    AreaCalculator ac;

    int squareSide = 5;
    cout << "Area of square with side " << squareSide << " is: " << ac.calculateArea(squareSide) << endl;

    int length = 10, breadth = 5;
    cout << "Area of rectangle with length " << length << " and breadth " << breadth << " is: " << ac.calculateArea(length, breadth) << endl;

    float radius = 3.5;
    cout << "Area of circle with radius " << radius << " is: " << ac.calculateArea(radius) << endl;

    return 0;
}