#include<iostream>

using namespace std;

template<typename T,int length>

class Array{
    
    public:
    T arr[length];
    void fill(T value){
        for(int i=0;i<length;i++){
            arr[i]=value;
        }
    }
    T& ind(int index)
    {
        return arr[index];
    }
    T print(){
        for(int i=0;i<length;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

// function template
template <typename T>
T maxi(T a,T b){
    if(a>b) return a;
    else return b;
}


int main(){

    Array<int,10> arr;

    arr.fill(5);
    arr.print();


    Array<string,5> str;

    str.fill("xyz");
    str.ind(2)="zyx";

    cout<<"Using string:"<<endl;
    str.print();

    // int x;
    // cin>>x;
    // Array<double,x> d; values should be given at compile time so x produces error

    int max= maxi(90,91);

    double d_max=maxi(2.35,3.11);

    cout<<"Integer max "<<max<<endl;
    cout<<"Double max "<<d_max<<endl;


}