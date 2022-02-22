#include <stdio.h>
#include<iostream>

using namespace std;


void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int findmax(int A[ ], int n)
{
    int max = A[0];
    for (int x= 0; x< n; x++)
    {
        if (max < A[x])
            max = A[x];
        
    }
    return max;
}
void swap(int &x, int &y)
{
    int temp;
    temp =x;
    x= y;
    y= temp;
}

int * fun(int size)
{
    int *p;
    p = new int[size];
    for (int i = 0; i < size; i++)
        p[i]=i+1;
        return p;
}
int main()
{
    int num1= 10, num2 = 15, sum;
    swap(num1, num2);
    cout<<num1<<endl;
    int A[]= {2, 4, 6, 10, 8};
    cout<<findmax(A, 5)<<endl;
    int *ptr, sz = 5;
    ptr = fun(sz);
    for(int i = 0; i< sz; i++)
    {   
        cout<<ptr[i]<<endl;
    }
}