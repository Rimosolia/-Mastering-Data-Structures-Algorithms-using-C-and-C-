#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    char A[] = "Finding";
    char B[] = "Duplicates";
    long int H= 0, x=0;
    for (int i = 0; A[i] != '\0'; i++)
    {
        x=1;
        x=x<<(A[i]-'a');
        if ((x&H)>0)
        {
            cout<<"Duplicate found: " << A[i] << endl;
        }
        else
        {
            H=H|x; 
        }
    }
}