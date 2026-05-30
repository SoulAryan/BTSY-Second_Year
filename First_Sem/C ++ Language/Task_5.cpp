#include <iostream>
using namespace std;
class Student{
private:
      int RollNo;

protected:
      string grade;

public:
      string name;
      
      void setRollNo(int roll)
      {
            RollNo=roll;
      }

      int getRollNo()
      {
            return RollNo;
      }

      void setgrade(string Grade)
      {
            grade=Grade;
      }

};

class Result : public Student{
public:
      void display()
      {
            cout <<"Grade of the Student="<<grade<<endl;
      }

};

int main()
{
      Result r;
      r.setRollNo(8);
      r.setgrade("A+");
      r.name="Aryan Suryavanshi";

      cout <<"\nRoll Number of the Student="<<r.getRollNo()<<endl;
      cout <<"Name of the Student="<<r.name<<endl;
      r.display();
      printf("\n");

      return 0;
}