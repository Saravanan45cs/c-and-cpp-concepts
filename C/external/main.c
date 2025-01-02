#include<stdio.h>

extern int add(int a,int b);
extern void details(char *name);

int main(){
    int x=54,y=7;
    printf("Sum of x and y =%d\n",add(x,y));

     details("abc");
}