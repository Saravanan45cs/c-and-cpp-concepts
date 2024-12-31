#include<stdio.h>

struct S{
    int n;
    unsigned int a:2;
    unsigned int b:5;
}; //8


struct S1{
    unsigned int a:2;
    int n;
    unsigned int b:5;
    
}; //12

struct num{
    int x:2;
    int y:3;
    int z:5;

};

struct foo {
    union {
        int i ;
        char c ;
    } u;

    unsigned int bar;
    short s ;
    unsigned int flag_s: 1;
    unsigned int flag_u: 2;
};
int main(){

    printf("Size of struct S: %d\n",sizeof(struct S));//8

    printf("Size of struct S1: %d\n",sizeof(struct S1));//12

    struct num n={2,5,31};

    printf("x,y,z= %d %d %d \n",n.x,n.y,n.z);//-2 -3 -1. 
    //Signed cannot be used as if msb is 1 it considers it as negative and calculates the 2s coomplement.

    printf("Size of struct foo: %d\n",sizeof(struct foo));//16
    return 0;

}