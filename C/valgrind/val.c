#include<stdio.h>
#include<stdlib.h>
int main(){
    int *ptr=(int *)malloc(5*sizeof(int));

    for(int i=0;i<5;i++){
        scanf("%d",ptr+i);
    }

    printf("Stored values using malloc: ");
    for(int i=0;i<5;i++){
        printf("%d ",*(ptr+i));
    }
    printf("\n");

    //free(ptr);
    return 0;
}