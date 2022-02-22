#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p;
    int i;


    p = (int *) malloc(5*sizeof(int));
    p[0]=3;
    p[1]= 6;
    p[2]= 2;
    p[3]= 20;
    
    for (int i=0;i<3;i++)
        printf("%d ", p[i]);
    return 0;
}