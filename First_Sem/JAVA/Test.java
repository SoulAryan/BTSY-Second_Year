/*class Account
{
    int balance=1000;

    synchronized void withdraw(int amount)
    {
        if(balance>=amount)
        {
            balance-=amount;
            System.out.println("Withdraw:" + amount +"|Balance:"+balance);
        }

        else
        {
            System.out.println("Insufficient Balance");
        }

    }
}

class MyThread extends Thread
{
    Account acc;
    int amount;
    MyThread(Account acc,int amount)
    {
        this.acc=acc;
        this.amount=amount;
    }

    public void run()
    {
        acc.withdraw(amount);
    }
}

public class Test
{
    public static void main(String[]args)
    {
            Account acc=new Account();
            MyThread t1=new MyThread(acc,1500);
            MyThread t2=new MyThread(acc,800);
            t1.start();
            t2.start();

    }
}*/

class Account
{
    int balance=1000;

    public void withdraw(int amount)
    {
        if(balance>=amount)
        {
            balance-=amount;
            System.out.println("Withdraw:" + amount +"|Balance:"+balance);
        }

        else
        {
            System.out.println("Insufficient Balance");
        }

    }
}

class MyThread extends Thread
{
    Account acc;
    int amount;
    MyThread(Account acc,int amount)
    {
        this.acc=acc;
        this.amount=amount;
    }

    public void run()
    {
        acc.withdraw(amount);
    }
}

public class Test
{
    public static void main(String[]args)
    {
            Account acc=new Account();
            MyThread t1=new MyThread(acc,1500);
            MyThread t2=new MyThread(acc,800);
            t1.start();
            t2.start();

    }
}
