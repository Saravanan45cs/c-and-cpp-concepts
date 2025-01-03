#include <stdio.h>
#include<stdlib.h>
void hello(){
    printf("Hello World!\n");
}

void printDetail(int marks,int regno,char *name){
    printf("Student :%s\nRegno: %d\nmarks %d\n",name,regno,marks);
}

int add(int a,int b){
    return a+b;
}

int sub(int a,int b){
    return abs(a-b);
}
int main(){

    void (*ptr)()=&hello;

    (*ptr)();

    //with arguments
    int marks=85;
    int regno=45;
    char *name="abc";
    void (*p)(int,int,char*)=&printDetail;

    (*p)(marks,regno,name);

    //with returntype
    int x=15,y=80;
    int (*ptrarr[])(int,int)={add,sub};

    int ch=1;
    int res=(*ptrarr[ch])(x, y);

    printf("Result: %d",res);


}