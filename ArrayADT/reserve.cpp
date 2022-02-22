//Include library
#include <iostream>
#include <stdio.h>
using namespace std;

struct Array
{
    int *A;
    int size;
    int length;
};

void Reverse(struct Array *arr)
{
    int *B;
    int i, j;

    B= (int *)malloc(arr->length*sizeof(int));
    for (int i = arr->length - 1, j=0 ; i> 0; i--,j++)
    {
        B[j] = arr->A[i];
    }
    for (int i = 0; i < arr->length; i++)
    {
        arr->A[i] = B[i];
    }
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void Reverse2(struct Array *arr)
{
    int i,j;
    for (i= 0, j= arr->length-1;i < j; i++, j--)
    {
        swap(&arr->A[i], &arr->A[j]);
    }
}
int main()
{
    //Create a struct named Array
    struct Array arr;
    arr.A = new int[10];
    arr.size = 10;
    arr.length = 0;
    int i;
    for (i = 0; i < 10; i++)
    {
        arr.A[i] = i;
    }
    arr.length = 10;
    Reverse(&arr);
}