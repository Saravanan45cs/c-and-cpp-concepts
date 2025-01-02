#include <stdio.h>

int main(){
    char c='a';
    putchar(c);
    printf("\n");

    // char ch;
    // ch=getchar();
    // printf("\n%d",ch);


    char arrn[20];
    char arr[10];
    sprintf(arr, "Hello %s!", "World");
    printf("%s", arr);
    snprintf(arrn, 20, "Hello %s and %s!", "World","People");//"Peo" since size is less
    printf("%s",arrn);

}