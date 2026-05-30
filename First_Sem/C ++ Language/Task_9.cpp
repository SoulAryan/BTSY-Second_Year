//The use of constructor and destructor in C++//
#include <iostream>
using namespace std;
class Employee
{
public:
      int empID;
      string empName;
      float salary; 
      
      Employee(int id,string name,float sal)
      {
            empID = id;
            empName = name;
            salary = sal;

            cout << "Employee ID: " << empID << endl;
            cout << "Employee Name: " << empName << endl;
            cout << "Salary: " << salary << endl;
      }

      ~Employee() // Destructor
      {
            cout << "Destructor called for Employee ID: " << empID << endl;
      }
};

int main()
{
    Employee emp1(101,"John Wick",3400000.60);
    Employee emp2(102,"Caine",450000.78);
    return 0;
}