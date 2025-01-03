#include<iostream>
#include <new>
using namespace std;

class Student{
    public:
    string name;
    Student(string name){
        this->name=name;
    }

    void print(){
        cout<<"Student registered: "<<name<<endl;
    }
};


int main(){

    int x=4;
    int *ptr=new int(7);

    //delete ptr; leaks 4 byte
    cout<<*ptr;

    //Student s1=new Student("John"); 
    // new creates object in heap and provides a pointer to the object so this is wrong

    Student *s1=new Student("John");
    (*s1).print(); //or 
    s1->print();

    //delete s1;

    //handling dynamic mem allocations

    try{
        double *arr= new double[99999];
    }
    catch (bad_alloc &exp){
        cout<<exp.what()<<endl;
    }

    //reuse memory
    double *first=new double(222.2);
    double *n=new(first) double(32.1);

    cout<<*first<<endl;//32.1

}