#include <iostream>

using namespace std;

class abc{
    private:
    int private_var;

    protected:
    int protected_var;

    public:
    abc(int x,int y){
        private_var=x;
        protected_var=y;
    }
    //accessing private and protected 
    friend void access(abc &obj);
};

 void access(abc &obj){
    cout<<"Private and protected accessed\n";
    cout<<obj.private_var<<" "<<obj.protected_var<<endl;
}

int main(){
    abc a(45,23);

    access(a);
}