#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <time.h>


int sum(int n,...) {
    va_list args;
    va_start(args, n);  
    int res=0;
    for (int i = 0; i < n; i++) 
        res+=va_arg(args,int);
    //printf("Sum= %d\n", res);
    va_end(args);

     return res;
}


int main() {
  
    int res1,res2;
    res1=sum(3, 1, 2, 3);
    
    res2=sum(5, 1, 2, 3, 4, 5);

    printf("%d\n%d",res1,res2);


 srand(time(NULL));

  printf("Random numbers :");
  for(int i = 0; i < 10; i++) {
    int num = rand() % 100 + 1;
    printf("%d ", num);
  }
  printf("\n");
  
    return 0;
}