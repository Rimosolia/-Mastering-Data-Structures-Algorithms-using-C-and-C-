#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int main()
{
    int a = 10;
    int *p;
    p = &a;
    printf("using pointer %d \n", *p);


    int A[5] = {2,4,6,8,10};
    p= A;
    cout<<p[2]<<endl;

    p=(int *)malloc(5*sizeof(int)); //Require stdlib.h, p= new int[5] C++

    p[0] = 10; p[1] = 15;

    free(p);
    return 0;
}