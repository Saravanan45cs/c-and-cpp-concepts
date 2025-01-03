#include<iostream>

using namespace std;

class Common{
    public:
    int commonval;

    Common(int commonval): commonval(commonval){}

    //Common():commonval(-99){}
};


class Base1 :virtual public Common{

    public:
    Base1():Common(100){}
    void print(){
        cout<<"Base1 called"<<endl;
    }
};

class Base2 :virtual public Common{

    public:
    Base2():Common(200){}
    void print(){
        cout<<"Base2 called"<<endl;
    }
};

class Derived : public Base1,public Base2{

    public:
    // void print(){
    //     cout<<"Derived called"<<endl;
    // }

    Derived():Common(9999){}

};

int main(){
    Derived d;
    Base1 b1;
    //d.commonval=10; //ambiguous call so we can use virtual 
    cout<<b1.commonval<<endl;
    

}