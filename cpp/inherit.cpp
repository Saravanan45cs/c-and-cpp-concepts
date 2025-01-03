#include <iostream>

using namespace std;

class Student{

    public:
     string name;
     int age;

     Student(string name,int age) {
        this->name=name;
        this->age=age;
     }

     void print(){
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<< age<<endl;
     }

};

class Graduated : public Student
{
    public:
    int year;
    Graduated(string name ,int age,int year):Student(name,age){
        this->year=year;
    }

    void grad(){
        Student::print();
        cout<<"Graduated year: "<<year<<endl;
    }
};


class Base1{

    public:
    void print(){
        cout<<"Base1 called"<<endl;
    }
};

class Base2{

    public:
    void print(){
        cout<<"Base2 called"<<endl;
    }
};

class Derived : public Base1,public Base2{

    public:
    // void print(){
    //     cout<<"Derived called"<<endl;
    // }
};

int main(){
    Student s1("John",25);

    Graduated g("Alice",22,2019);

    s1.print();
    g.grad();


    //multiple inheritance
    Derived d;
    //d.print();//overrides print() if available and prints Derived called

    d.Base2::print();//if not specify the class with scope resolution op




}