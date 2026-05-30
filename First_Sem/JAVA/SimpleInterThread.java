class  ShareData
{
    private boolean ready=false;

    synchronized void waitforsignal()
    {
        System.out.println("Thread is running");

        try
        {
            while(!ready)
            {
                wait();
            }
        }

        catch(InterruptedException e)
        {
            System.out.println(e);     
        }

        System.out.println("Thread got the signal and resumed");
    }

    synchronized void sendsignal()
    {
        System.out.println("Signal send by another thread");
        ready=true;
        notify();
    }
}

public class SimpleInterThread
{
    public static void main(String[]args)
    {
        ShareData data=new ShareData();

        Thread t1=new Thread(()->data.waitforsignal());
        Thread t2=new Thread(()->
        {
            try
            {
                Thread.sleep(2000);
            }

            catch(Exception e)
            {
                
            }

            data.sendsignal();
        });

        t1.start();
        t2.start();
        
    }
}
