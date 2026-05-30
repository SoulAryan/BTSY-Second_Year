class Student
{
    int age;
    String name;

    //Parameterized Constructor
    Student(String name,int age)
    {
        this.name=name;
        this.age=age;
    }

    void display()
    {
        System.out.println("Name: "+name);
        System.out.println("Age: "+age);
    }

}
public class Paramerterized_Constructor
{
    public static void main(String[]args)
    {
        Student s=new Student("Aryan",20);
        s.display();
    }
    
}
