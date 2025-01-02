#include <assert.h>//checks logically impossible situations
#include <stdio.h>

#define SIZE 16 
#if (17 > SIZE)
//#error my_data_type is too big
#endif

struct s{
    double d;
    float f;
    int i;
};
int main(){

    int x=5;

    printf("%d\n",x);
    //x=7;
    //assert(x==5);

    printf("Value doesnt changed\n");
    assert(sizeof(struct s)<15);


}