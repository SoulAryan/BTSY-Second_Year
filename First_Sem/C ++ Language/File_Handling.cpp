//Write Operations//
/*
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char arr[100];
    cout<<"Enter your name and age:"<<endl;
    cin.getline(arr,100);

    ofstream myfile("sample.txt");
    if(!myfile)
    {
        cout<<"File creation error"<<endl;
        return 1;
    }
    else
    {
        myfile<<arr;
        cout<<"Text written to the file successfully"<<endl;
        myfile.close();
 }
    
    return 0;
}*/

//Read Operations//
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    cout<<"WRITING TO A FILE"<<endl;
    char xyz[100];
    cout<<"Enter your name and age:"<<endl;
    cin.ignore();
    cin.getline(xyz,100);


    ofstream myfile("sample.txt");
    if(!myfile)
    {
        cout<<"File did not open for writing"<<endl;
        return 1;
    }
    
    else
    {
        myfile<<xyz;
        cout<<"Text written to the file successfully"<<endl;
        myfile.close();
    }
    
    cout<<"READING FROM A FILE"<<endl;
    char arr[100];
    ifstream obj("sample.txt"); 
    
    cout<<"Text read from the file successfully"<<endl;
    cout<<"Contents of the file:"<<endl;

    string line;
    while(getline(obj,line))
    {
        cout<<line<<endl;
    }
    obj.close();
    return 0;
}

//Append Operation//    
/*#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    cout<<"Appending To A File"<<endl;
    char arr[100];
    cout<<"Enter your name and RollNo"<<endl;
    cin.ignore();
    cin.getline(arr,100);
    ofstream myfile("sample.txt",ios::app);
    if(!myfile)
    {
        cout<<"File did not open for writing"<<endl;
        return 1;
    }
    
    else
    {
        myfile<<arr<<endl;
        cout<<"Writing operation successfully completed"<<endl;
        myfile.close();
    }

    cout<<"Reading From A File"<<endl;
    char arr1[100];
    ifstream obj("sample.txt");
    obj.getline(arr1,100);
    cout<<"Reading operation completed successfully"<<endl;
    cout<<"Contents of the file:"<<arr1<<endl;
    obj.close();

    return 0;
}*/