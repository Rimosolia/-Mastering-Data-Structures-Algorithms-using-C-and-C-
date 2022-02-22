//Import library
#include <iostream>
#include <stdio.h>
using namespace std;

//Create a struct named Array
struct Array
{
    int *A;
    int size;
    int length;

};


//Function Display for print out arr.A
void Display(Array arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << " ";
    }
    cout << endl;
}

void Append(Array *arr, int x)
{
    if(arr->length < arr->size)
    {
        arr->A[arr->length] = x ;
        arr->length++;
    }
}

void Insert(Array *arr, int index, int x)
{
    int i;
    if (index>= 0 && index <= arr->length)
    {
        for (int i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

void Delete(Array *arr, int index)
{
    if (index >= 0 && index < arr-> length)
    {
        for (int i= index; i<arr->length-1;i++)
            arr->A[i] = arr-> A[i+1];
        arr->length--;
    }
}

int LinearSearch(Array arr, int key)
{
    for (int i =0; i< arr.length; i++)
    {
        if (key==arr.A[i])
            return i;
    }
    return -1;
}
int BinarySearch(Array arr, int key)
{
    int l = 0;
    int r = arr.length - 1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (key == arr.A[m])
            return m;
        else if (key < arr.A[m])
            r = m - 1;
        else
            l = m + 1;      
    }
    return 0;
}

int Get(Array arr, int index)
{
    if (index >= 0 && index < arr.length)
        return arr.A[index];
    else
        return -1;
}

int Set(Array *arr, int index, int x)
{
    if (index >= 0 && index < arr->length)
    {
        arr->A[index] = x;
        return 1;
    }
    else
        return 0;
}
int Max(Array arr)
{
    int max = arr.A[0];
    for (int i = 1; i< arr.length; i++)
    {
        if (arr.A[i] > max)
            max = arr.A[i];
    }
}


int main()
{
    struct Array arr;
    printf("Enter size of an array \n");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size*sizeof(int));
    arr.length=0;
    //Input arr.A pointer
    printf("Enter elements of an array \n");
    for (int i=0; i<arr.size; i++)
    {
        //input arr.A[i], check if value is equal = -1 then stop
        scanf("%d", &arr.A[i]);
        if(arr.A[i] == -1)
        {
            break;
        }
        arr.length++;   

    }
    Append(&arr, 5);
    Insert(&arr, 1, 69);
    Delete(&arr, 1);
    Display(arr);
    int key;
    printf("Enter key to search \n");
    scanf("%d", &key);
    int index = LinearSearch(arr, key);
    if (index == -1)
    {
        printf("Not found \n");
    }
    else
    {
        printf("Found at index %d \n", index);
    }
    index = BinarySearch(arr, key);
    if (index == -1)
    {
        printf("Not found \n");
    }
    else
    {
        printf("Found at index %d \n", index);
    }
    printf("Enter index to get \n");
    scanf("%d", &index);
    int x = Get(arr, index);
    if (x == -1)
    {
        printf("Not found \n");
    }
    else
    {
        printf("Found at index %d \n", x);
    }
    printf("Enter index to set \n");
    scanf("%d", &index);
    printf("Enter value to set \n");
    scanf("%d", &x);
    int result = Set(&arr, index, x);        
    return 0;
}