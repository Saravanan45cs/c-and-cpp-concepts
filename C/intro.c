#include<stdio.h>

char arr[100];

int main(){
    struct arr{
        char a[101];
    };

    int size=sizeof(arr);
    printf("%d\n",size);//global value 100
}