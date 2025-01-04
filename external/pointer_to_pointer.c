#include <stdio.h>


void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

// void swap(int &a, int &b) { // Pass by reference in cpp
//     int temp = a;
//     a = b;
//     b = temp;
// }

int main(){
    int num=22;
    int *ptr=&num;

    int **q=&ptr; //pointer to pointer;

    printf("%u %u\n",&ptr,q);//6422292

    num=100;

    printf("%d %d\n",*ptr,**q);//100 100

    //swap two values
    int a=5;
    int b=7;

    swap(&a ,&b);

    printf("Swapped values: a=%d b=%d\n",a,b);//7 5
}