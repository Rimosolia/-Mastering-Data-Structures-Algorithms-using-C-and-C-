#include<stdio.h>
#include<iostream>

using namespace std;

//Menu for Lower Triangular Matrix

class Diagonal
{
    private: int *A, n;
    public:
    Diagonal(int n)
    {   
        this->n = n;
        A = new int [n*(n+1)/2];
    }
    ~Diagonal()
    {
        delete []A;
    }
    void Create();
    void Display();
    int Get(int i, int j);
    void Set(int i, int j, int x);
};

void Diagonal::Create()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= j)
            {
                int dex = (i*(i-1)/2) + j - 1;
                printf("Enter A[%d][%d]: ", i, j);
                cin>>A[dex];
            }
            else
            {
                int dex = ((i*(i-1))/2) + j - 1;
                A[dex] = 0;
            }
        }
    }
}
int Diagonal::Get(int i, int j)
{
    if (i >= j)
    {
        int dex = ((i*(i-1))/2) + j - 1;
        return A[dex];
    }
    else
        return 0;
}

void Diagonal::Set(int i, int j, int x)
{
    if (i >= j)
    {
        int dex = ((i*(i-1))/2) + j - 1;
        A[dex] = x;
    }
}

void Diagonal::Display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= j)
            {
                int dex = ((i*(i-1))/2) + j - 1;
                cout << A[dex] << " ";
            }
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the size of the matrix: ";
    cin >> n;
    Diagonal D(n);
    D.Create();
    D.Display();
    return 0;
}