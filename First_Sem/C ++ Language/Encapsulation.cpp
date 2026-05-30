/////////////////////////////////////////////////BANK ACCOUNT/////////////////////////////////////
#include <iostream>
using namespace std;

class BankAccount
{
private:
      int accountNumber;
      int balance;

public:
      int deposit()
      {
        int amount;
        cout<<"Enter the amount to deposit"<<endl;
        cin>>amount;

        balance+=amount;
        cout<<"Amount Deposited: "<<amount<<endl;
        cout<<"New Balance: "<<balance<<endl;
        return balance;
      }
   
      int withdraw()
      {
        int withdraw_amount;
        cout<<"Enter the amount to withdraw"<<endl;
        cin>>withdraw_amount;    

        if(withdraw_amount>balance)
        {
            cout<<"Sorry,cannot withdraw the amount"<<endl;
        }

        else
        {
            balance-=withdraw_amount;
            cout<<"Amount Withdrawn: "<<withdraw_amount<<endl;
            cout<<"New Balance: "<<balance<<endl;
        }
        return balance;

      }
      
        BankAccount(int accNum, int bal)
        {
            accountNumber = accNum;
            balance = bal;
        }

        void setaccountNumber(int accNum)
        {
            accountNumber = accNum;
        }

        int getaccountNumber()
        {
            return accountNumber;
        }

        void setbalance(int bal)
        {
            balance = bal;
        }

        int getbalance()
        {
            return balance;
        }

        void displayBalance()
        {
            cout << "Account Number: " << accountNumber << ", Balance: " << balance << endl;
        }

        ~BankAccount()
        {
            cout << "Destructor called for Account Closed for XYZ: " << accountNumber << endl;
        }

};

int main()
{
    BankAccount A(123456, 100000);
    A.displayBalance();
    A.deposit();
    A.withdraw();
    return 0;
}