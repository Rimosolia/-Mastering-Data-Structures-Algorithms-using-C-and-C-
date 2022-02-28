#include<stdio.h>
#include<iostream>
using namespace std;
class LTMatrix
{
    private:
        int *A;
        int n;
    public:
        LTMatrix(int n)
        {
            this->n =  n;
            A= new int [n*(n+1)/2];
        }
        ~LTMatrix()
        {
            delete []A;
        }
        void Display(bool row= true);
        void setRowMajor(int i, int j, int x);
        int getRowMajor(int i, int j);
        void setColumnMajor(int i, int j, int x);
        int getColumnMajor(int i, int j);
        int getN(){return n;}

};

void LTMatrix::setRowMajor(int i, int j, int x)
{
    if (i>= j)
    {
        int dex = ((i*(i-1))/2) + j - 1;
        A[dex] = x;
    }
}
void LTMatrix::setColumnMajor(int i, int j, int x)
{
    if (i>= j)
    {
        int dex = (n*(j-1)-(((j-1)*(j-2))/2)) + (i-j);
        A[dex] = x;
    }
}
int LTMatrix::getRowMajor(int i, int j)
{
    if (i>= j)
    {
        int dex = ((i*(i-1))/2) + j - 1;
        return A[dex];
    }
    else
        return 0;
}
int LTMatrix::getColumnMajor(int i, int j)
{
    if (i>= j)
    {
        int dex = (n*(j-1)-(((j-1)*(j-2))/2)) + (i-j);
        return A[dex];
    }
    else
        return 0;
}

void LTMatrix::Display(bool row) {
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (i >= j){
                if (row){
                    cout << getRowMajor(i, j) << " ";
                } else {
                    cout << getColumnMajor(i, j) << " ";
                }
            } else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int d;
    cout<<"Enter the dimension of the matrix: ";
    cin>>d;

    LTMatrix A(d);

    int x;
    cout<<"Enter All Elements of the matrix: ";
    for (int i=1; i<=d; i++)
    {
        for (int j=1; j<=d; j++)
        {
            cin>>x;
            A.setRowMajor(i,j,x);
        }
    }
    A.Display();
    return 0;
}
