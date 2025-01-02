#include <iostream>


char arr[100];

int main(){
    struct arr{
        char a[101];

    };
    int size;
    size=sizeof(arr);
    std::cout<<size<<std::endl;//101
}