#include <iostream>
using namespace std;

int add(int a,int b)
{
    cout<<"First Function Called"<<endl;
    return (a+b);
}

double add(double a,double b)
{
    cout<<"Second Function Called"<<endl;
    return (a+b);
}

int add(int a,double b)
{
    cout<<"Third Function Called"<<endl;
    return (a+b);
}

double add(double a,int b)
{
    cout<<"Fourth Function Called"<<endl;
    return (a+b);
}

float add(int a,float b)
{
    cout<<"Fifth Function Called"<<endl;
    return (a+b);
}

int main()
{
    cout<<add(7,6)<<endl;
    cout<<add(3.5678,2.1234)<<endl;
    cout<<add(45,6.7543)<<endl;
    cout<<add(4.3456,98)<<endl;
    cout<<add(34,(float)5.67)<<endl;

    return 0;

}