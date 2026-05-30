#include <iostream>
using namespace std;

class Animal
{
public:
      virtual void speak()
      {
        cout <<"Animal makes sound"<<endl;
      }    
};

class Dog:public Animal
{
public:
     void speak() override
     {
        cout <<"Dog barks"<<endl;
     }    
};

class Cat:public Animal
{
public:
     void speak() override
     {
        cout <<"Cat Meows"<<endl;
     }    
};

int main()
{
    Animal* animalPtr;

    Dog dog;
    Cat cat;

    animalPtr = &dog;
    animalPtr->speak(); // Output: Dog barks

    animalPtr = &cat;
    animalPtr->speak(); // Output: Cat Meows

    return 0;
}
