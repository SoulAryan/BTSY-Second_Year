///////////////////////OPERATOR OVERLOADING/////////////////////

/*#include <iostream>
using namespace std;

class Data
{
public:
     int num1;
     
     Data(int n)
     {
        num1=n;
     }

     Data operator+(Data t2)
     {
        Data t3(0);
        t3.num1=num1 + t2.num1;
        return t3;
    }

    void display()
    {
        cout<<"The sum is:"<<num1<<endl;
    }
};

int main()
{
    Data t1(10);
    Data t2(20);
    
    Data t3 = t1 + t2; // Using overloaded + operator

    t3.display(); // Displaying the result

    return 0;    
}*/

/*#include <iostream>
using namespace std;
class Sum
{
public:
    int real,img;
    Sum(int r,int i)
    {
        real=r;
        img=i;
    }
    
    Sum operator+(Sum t2)
    {
        Sum t3(0,0);
        t3.real=real+t2.real;
        t3.img=img+t2.img;
        return t3;
    }

    void display()
    {
        cout<<"The sum is: "<<real<<" + "<<img<<"i"<<endl;
    }
};

int main()
{
    Sum t1(10,5);
    Sum t2(20,10);
    
    Sum t3 = t1 + t2; // Using overloaded + operator

    t3.display(); // Displaying the result

    return 0;
}*/
#include <iostream>
using namespace std;

class ComplexNumber
{
private:
     int real;
     int imag;
     
public:
    ComplexNumber()   //Default Constructor
    {
        real=0;
        imag=0;
    }

    ComplexNumber(int r,int i)   //Parameterized Constructor
    {
        real=r;
        imag=i;
    }

    //Operator Overloading
    ComplexNumber operator +(ComplexNumber CN)
    {
        ComplexNumber temp;
        temp.real=real+CN.real;
        temp.imag=imag+CN.imag;

        return temp;
    }


    void display()
    {
        cout<<real <<" + "<<imag<<"i"<<endl;
    } 
};

int main()
{
    ComplexNumber c1(12,67);
    ComplexNumber c2(34,78);
    ComplexNumber c3;

    c3=c1+c2;

    c3.display();

    return 0;
}

