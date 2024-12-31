#include <stdio.h>

int main(){
    int n=22;
    int *p=&n;

    n=20;
    printf("%d\n",*p);//20

    printf("%u\n",p); //6422296

    p++;
    printf("Integer Pointer increment: ");
    printf("%u\n",p); //6422300

    char c[]="abc";
    char *ptr=c;

    printf("%c\n",*ptr); //a

    ptr++;
    printf("Character increment: ");
    printf("%c\n",*ptr); //b

    int a[]={1,2,3,4,5};
    int *arr=a;

    printf("%d\n",*arr);//1
    printf("%u\n",arr);//6422264
    arr+=4;
    printf("Value: %d\n",*arr);//5
    printf("Address: %u\n",arr);//6422280




}