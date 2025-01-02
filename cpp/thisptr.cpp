#include <iostream>

using namespace std;

class Student;
void add_info(Student *student);

class Student{
    public:
    string name;
    int age;
    int regno;

    Student(string name,int age){
        this->name=name;
        this->age=age;
    }
    void print(){
        cout<<"this address "<<this<<endl;//pointer to object instance student1
        cout<<"Student: "<<name<<" Age: "<<age<<endl;
    }

    void change_name(){
        this->name="abc";
    }
    void print_changes(){
        this->change_name();
        cout<<"Changed name: "<<this->name<<endl;
    }

    void add_info(Student *student,int regno)
    {
        this->regno=regno;
        cout<<"Added regno"<<endl;
        cout<<"Name : "<<student->name<<" Age: "<<this->age<<" Regno : "<<regno<<endl;
    }
};


int main(){
    Student student1("xyz",20);
    cout<< "Address of student1: "<<&student1<<endl;
    student1.print();
    student1.print_changes();
    student1.add_info(&student1,44);
}