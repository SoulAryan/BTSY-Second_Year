//Constructor
class Student 
{
    int rollno;
    String name;

    void display()
    {
        System.out.println("Name: "+name);
        System.out.println("Roll No: "+rollno);
    }
}
public class Constructor{
    public static void main(String[] args)
    {   
        Student s=new Student();
        s.name="Aryan";
        s.rollno=8;
        s.display();
    }
}
