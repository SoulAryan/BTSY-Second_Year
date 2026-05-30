#include <iostream>
using namespace std;

class Employee
{
protected:
       string empName;
       int empID;
       
public:
      void setEmployee(int id,string name)
      {
            empID=id;
            empName=name;
      }

      void displayEmployee()
      {
            cout << "Employee ID="<<empID << endl;
            cout << "Employee Name="<<empName <<endl;
      }
};


class Manager : public Employee
{
private:
        string department;
        float bonus;
        
public:
        void setManagerDetails(string dept,float bonusamount)
        {
            department=dept;
            bonus=bonusamount;
        }
        
        string getdepartment()
        {
            return department;
        } 

        float getbonus()
        {
            return bonus;
        }

        void displayManagerDetails()
        {
            cout <<"Manager's Department="<<department<<endl;
            cout <<"Manager's Bonus="<<bonus<<endl;
        }
};

int main()
{
    Manager m;
    m.setEmployee(456,"Satoshi");
    m.setManagerDetails("Technology",2000.50);
    m.displayEmployee();
    m.displayManagerDetails();
    printf("\n");

    return 0;
}