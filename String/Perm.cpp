#include<iostream>
#include<stdio.h>
using namespace std;

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void Perm(char s[], int l, int h)
{
    if (l==h) printf("%s \n", s);
    else
    {
        for (int i = l; i <= h; i++)
        {
            swap(s[l], s[i]);
            Perm(s, l+1, h);
            swap(s[l], s[i]);
        }
    }
}

int main()
{
    char s[] = "abcd";
    int l = 0, h = 3;
    Perm(s, l, h);
}