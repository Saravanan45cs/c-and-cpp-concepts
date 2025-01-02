#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d",&n);

    int* ptr=(int*)malloc(n*sizeof(int));
    //returns void pointer so we have to typecast it
    //initialized with some garbage values

    for(int i=0;i<n;i++){
        scanf("%d",ptr+i);
    }

    printf("Stored values using malloc: ");
    for(int i=0;i<n;i++){
        printf("%d ",*(ptr+i));
    }
    printf("\n");

    int *cal=(int*)calloc(n,sizeof(int));
    //initialize with zeros and has 2 aruguments

    for(int i=0;i<n;i++){
        scanf("%d",cal+i);
    }
    printf("Stored values using calloc :");
    for(int i=0;i<n;i++){
        printf("%d ",*(cal+i));
    }
    printf("\n");


    //realloc
    ptr=(int*)realloc(ptr,5*sizeof(int));
    printf("Enter 5 more numbers\n");

    for(int i=n;i<n+5;i++){
        scanf("%d",ptr+i);
    }

    for(int i=n;i<n+5;i++){
        printf("%d ",*(ptr+i));
    }
    //deallocate
    free(ptr);
    free(cal);
}