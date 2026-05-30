

//Default Constructor

class Student
{
    int age;
    String name;

    Student()
    {
        System.out.println("Constructor Called");
    }

    void display()
    {
        System.out.println("Name: "+name);
        System.out.println("Age: "+age);
    }
}

class DefaultConstructor
{
    public static void main(String[] args)
    {
    
        Student s=new Student();
        s.name="Aryan";
        s.age=20;
        s.display();
    }
}
