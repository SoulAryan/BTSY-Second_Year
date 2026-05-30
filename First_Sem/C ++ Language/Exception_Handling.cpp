#include <iostream>
using namespace std;

int main()
{
    try
    {
        int a;
        int b;
        cout<<"Enter first number"<<endl;
        cin>>a;
        cout<<"Enter second number"<<endl;
        cin>>b;

        if(b==0)
        {
            throw(b);
        }

        else
        {
            int c=a/b;
            cout<<"Result: "<<c<<endl;
        }
        
    }

    catch(int x)
    {
        cout<<"Exception caught: Division by zero is not allowed."<<endl;
    }


    return 0;
    
}