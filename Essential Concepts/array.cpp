#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int A[5] = {2,4,6,8,10};
    cout<<sizeof(A)<<endl; //Cuz of 1 int value = 4 byte = > 4x5 = 20 byte
    cout<<A[1]<<endl; // iostream
    printf("%d \n", A[2]); // stdio.h

    for (int i=0;i<5; i++) //For loop
    {
        cout<<A[i]<<endl;
    }

    cout<<"Enter the value";
    cin>>A[0];

    for(int x:A) //Same as the above loop, but shorter
    {
        cout<<x<<endl;
    }    

    return 0;
}