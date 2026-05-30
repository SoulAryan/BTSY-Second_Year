class Person
{
    private String name;
    private int id;

    public void setname(String n)
    {
         this.name=n;       
    }

    public String getname()
    {
        return name;
    }

    public void setid(int i)
    {
        this.id=i;
    }

    public int getid()
    {
        return id;
    }

    public void display()
    {
        System.out.println("Name : "+name);
        System.out.println("ID : "+id);
    }
}

public class Main
{
    public static void main(String[]args)
    {
        Person myobj=new Person();
        myobj.setname("Aryan");
        myobj.setid(8);
        myobj.display();
    }
    
}
