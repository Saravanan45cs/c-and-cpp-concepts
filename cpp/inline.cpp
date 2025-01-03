#include <iostream>

using namespace std;
//slightly improves performance by providing a copy of the function but at the same time has memory issues
inline void length(string s);

int main(){

    length("abc");
    length("Ram");
    length("Inline functions");
    //increases memory usages;
    
    
}

void length(string s){
    int i=0;
    while(s[i]!='\0'){
        i++;

    }
    cout<<"length of "<<s<<": "<<i<<endl;
}