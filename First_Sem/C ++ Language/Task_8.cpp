/////////////////////////////////////////////SINGLE INHERITANCE///////////////////////////////////////

/*#include <iostream>
using namespace std;

class Emplyoee
{
private:
       string empname; 

protected:
        int ID;

public:
       void setEmployeeDetails(string name, int id)
       {
           empname = name;
           ID = id;
       }
       
       string getempname()
       {
            return empname;
       }
};

class Manager : public Emplyoee
{
 public:
       void display()
       {
            cout <<"Employee Name="<<getempname()<<endl;
            cout <<"Employee ID="<<ID<<endl;
       }   
};

int main()
{
    Manager m;
    m.setEmployeeDetails("Blue",101);
    m.display();
    cout <<"\n"<<endl;

    return 0;

}*/

///////////////////////////////////////MULTIPLE INHERITANCE////////////////////////////////////////////

/*#include <iostream>
using namespace std;

class employee
{
private:
      string name;
      int ID;

public:
       void setEmployeeDetails(string empName, int empID)
       {
           name = empName;
           ID = empID;
       }

       string getName()
       {
            return name;
       }

       int getIDNumber()
       {
            return ID;
       }
};

class Manager : public employee
{
private:
       string ManagerName;
       string Department;

public:
      void displayEmployeeDetails()
      {
           cout <<"Employee Name="<<getName()<<endl;
           cout <<"Employee ID="<<getIDNumber()<<endl;
      }

      void setManagerDetails(string Name,string dept)
      {
            ManagerName=Name;
            Department=dept;
      }

      string getManagerName()
      {
          return ManagerName;
      }

        string getDepartment()
        {
            return Department;
        }
};

class SeniorManager : public Manager 
{
public:

    void displayEmployeeDetails()
      {
           cout <<"Employee Name="<< getName()<<endl;
           cout <<"Employee ID="<< getIDNumber()<<endl;
      }

         void displayManagerDetails()
         {
              cout <<"Manager Name="<<getManagerName()<<endl;
              cout <<"Department="<<getDepartment()<<endl;
         }
};

int main()
{
    SeniorManager sm;
    sm.setEmployeeDetails("Arya", 101);
    sm.setManagerDetails("Dhawal", "Sales");

    sm.displayEmployeeDetails();
    sm.displayManagerDetails();

    return 0;
}*/

////////////////////////////////////////////MULTILEVEL INHERITANCE/////////////////////////////////////

/*#include <iostream>
using namespace std;

class Student
{
private:
      string studentname;  
protected:
      int RollNo;

public:
      void setStudentDetails(string name,int roll)
      {
          studentname=name;
          RollNo=roll;
      } 
      
      string getStudentName()
      {
          return studentname;
      }

};

class Teacher : public Student
{
public:
      void display()
      {
          cout <<"Roll Number of the Student="<<RollNo<<endl;
      }

      void displayStudentDetails()
      {
          cout <<"Name of the Student="<<getStudentName()<<endl;
          cout <<"Roll Number of the Student="<<RollNo<<endl;
      }

private:
      string Teacher_name;

protected:
       string subject;

public:
       void setTeacherDetails(string name,string sub)
       {
          Teacher_name=name;
          subject=sub;
       }

     string getTeacherName()
     {
            return Teacher_name;
     }

};

class Principal : public Teacher
{
public:
      void display()
      {
          cout <<"Subject taught by the Teacher="<<subject<<endl;
      }
      
     void displayTeacherDetails()
     {
          cout <<"Name of the Teacher="<<getTeacherName()<<endl;
     }
};

int main()
{
     Principal p;
     p.setStudentDetails("Aryan", 8);
     p.setTeacherDetails("Mr. Sharma", "Mathematics");    
     
     p.displayStudentDetails();
     p.displayTeacherDetails();
     p.display();
     printf("\n");

     return 0;
}*/

//////////////////////////////////////////////////HIERARCHICAL INHERITANCE//////////////////////////////////////////

/*#include <iostream>
using namespace std;

class Salary
{
private:
    string EmployeeName;
    int salary;
    
    string Team_Leader_name;
    int leader_salary;    

public:
    void setEmployeeDetails(string name, int sal)
    {
        EmployeeName = name;
        salary = sal;
    }

    string getEmployeeName()
    {
        return EmployeeName;
    }

    int getSalary()
    {
        return salary;
    }  
    
    void setTeamLeaderDetails(string name, int sal)
    {
        Team_Leader_name = name;
        leader_salary = sal;
    }

    string getTeamLeaderName()
    {
        return Team_Leader_name;
    }

    int getTeamLeaderSalary()
    {
        return leader_salary;
    }
};
class Employee : public Salary
{
public:
    void displayEmployeeDetails()
    {
        cout <<"Employee Name="<<getEmployeeName()<<endl;
        cout <<"Employee Salary="<<getSalary()<<endl;
    }
};

class TeamLeader : public Salary
{
public:
       void displayTeamLeaderDetails()
        {
            cout <<"\nTeam Leader Name="<<getTeamLeaderName()<<endl;
            cout <<"Team Leader Salary="<<getTeamLeaderSalary()<<endl;
            cout <<"\n"<<endl;
        }   
};

int main()
{
    Employee emp;
    emp.setEmployeeDetails("John Doe", 50000);
    emp.displayEmployeeDetails();

    TeamLeader TL;
    TL.setTeamLeaderDetails("Aryan Suryavanshi",90000);
    TL.displayTeamLeaderDetails();

    return 0;
}*/

///////////////////////////////////////////////////HYBRID INHERITANCE////////////////////////////////////

/*#include <iostream>
using namespace std;

class Employee
{
private:
      string EmpName;
      int EmpID;
public:
      void setEmployeeDetails(string name, int id)
      {
          EmpName = name;
          EmpID = id;
      }

      string getEmpName()
      {
          return EmpName;
      }

      int getEmpID()
      {
          return EmpID;
      }      
};

class Intern
{
private:
       string InternName;
       int InternID;
       
public:
       void setInternDetails(string name, int id)
       {
           InternName = name;
           InternID = id;
       }
       
       string getInternName()
       {
        return InternName;
       }

       int getInternID()
       {
        return InternID;
       }
};

class Manager : public Employee
{
public:
        void displayEmployeeDetails()
        {
            cout<<"Employee Name="<<getEmpName()<<endl;
            cout<<"Employee ID="<<getEmpID()<<endl;
        }
};

class SeniorManager : public Employee,public Intern
{
public:
        void displayDetails()
        {
            cout<<"Employee Name="<<getEmpName()<<endl;
            cout<<"Employee ID="<<getEmpID()<<endl;
            cout<<"\nIntern Name="<<getInternName()<<endl;
            cout<<"Intern ID="<<getInternID()<<endl;
            cout << "\n" << endl;
        }    
};

int main()
{
    SeniorManager sm;
    sm.setEmployeeDetails("Kshitij", 101);
    sm.setInternDetails("Kartik", 202);  
    sm.displayDetails();
    
    return 0;
}*/