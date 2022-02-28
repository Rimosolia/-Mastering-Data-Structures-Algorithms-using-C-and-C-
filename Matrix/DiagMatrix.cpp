//Code về ma trận chéo, tức là M[i,j] = 0 if i != j
#include<iostream>
#include<stdio.h>
using namespace std;
//C style
struct Matrix
{
    int A[10];
    int n;
};
void Set(struct Matrix *m, int i, int j, int x)
{
    if (i==j)
        m->A[i-1] = x;
}
int Get(struct Matrix m, int i, int j)
{
    if (i==j)
        return m.A[i-1];
    else
        return 0;
}
void Display(struct Matrix m)
{
    int i, j;
    for (i = 0; i<m.n; i++)
    {
        for (j= 0; j<m.n;j++)
            if (i==j)
                printf("%d ", m.A[i]);
            else
                printf("0 ");
            printf("\n");
    }
}

//C++ class style
class Diagonal
{
private:
    int *A;
    int n;
public:
    Diagonal()
    {
        n= 2;
        A= new int[2];
    }
    Diagonal(int n)
    {
        this->n= n;
        A= new int[n];
    }
    ~Diagonal()
    {
        delete []A;
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    int GetDimension(){return n;}
};

void Diagonal::Set(int i, int j, int x)
{
    if (i==j)
        A[i-1]= x;
}
int Diagonal::Get(int i, int j)
{
    if (i==j)
        return A[i-1];
    else   
        return 0;
}
void Diagonal::Display()
{
    int i, j;
    for (i = 0; i<n; i++)
    {
        for (j= 0; j<n;j++)
            if (i==j)
                cout<<A[i]<<" ";
            else
                cout<<"0 ";
        cout<<endl;
    }
}
int main()
{
    struct Matrix m;
    m.n = 4;
    Set(&m, 1, 1, 1);
    Set(&m, 3, 3, 69);
    Set(&m, 2, 2, 20);
    Set(&m, 4, 4, 10);
    Get(m, 1, 1);
    Get(m, 2, 2);
    Get(m, 3, 2);
    Display(m);

    int n;
    cout<<"Enter dimension: ";
    cin>>n;
    Diagonal d(n); 
    int x;
    cout<<"Enter all Elements: ";
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            cin>>x;
            d.Set(i, j, x);
        }
    }
    d.Display();
    return 0;
}
