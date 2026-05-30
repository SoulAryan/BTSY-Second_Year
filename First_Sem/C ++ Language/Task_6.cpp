#include <iostream>
using namespace std;

class BankAccount{
private:
        int Account_Number;
        double Balance;
protected:
        string Account_holder_Name;

public:
        string name;

        void setAccountDetails(int accountnumber,double balance,string name)
        {
                Account_Number=accountnumber;
                Balance=balance;
                Account_holder_Name=name;
        }

        int getAccountNumber()
        {
             return Account_Number;
        }

        double getBalance()
        {
            return Balance;
        }
};
class SavingsAccount : public BankAccount
{
private:
       double interest_rate;
public:
       void setinterest_rate(double rate)
       {
              interest_rate=rate;
       }

       double getinterest_rate()
       {
               return interest_rate;
       }

       void display()
       {
           cout <<"Account Holder Name="<<Account_holder_Name<<endl;
           cout <<"Interest Rate="<<interest_rate<<"%"<<endl;
       }

};

int main()
{
    SavingsAccount sa;
    sa.setAccountDetails(123456789,50000,"Aryan Suryavanshi");
    sa.setinterest_rate(3.5);

    cout <<"Account Number="<<sa.getAccountNumber()<<endl;
    cout <<"Balance="<<sa.getBalance()<<endl;
    sa.display();
    printf("\n");


    return 0;    
}