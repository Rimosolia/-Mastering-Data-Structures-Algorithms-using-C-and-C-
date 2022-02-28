#include <iostream>

using namespace std;

class Element
{
    public:
        int i;
        int j;
        int x;
};

class Sparse
{
    private:
        int m;
        int n;
        int num;
        Element *elements;
    public:
        Sparse(int m, int n, int num)
        {
            this->m = m;
            this->n = n;
            this->num = num;
            elements = new Element[this->num];
        }
        ~Sparse()
        {
            delete[] elements;
        }

        Sparse operator+(Sparse &s);

        friend istream & operator>>(istream &in, Sparse &s);
        friend ostream & operator<<(ostream &out, Sparse &s);

};

Sparse Sparse::operator+(Sparse &s)
{
    int i,j,k;
    if(m!= s.m || n!= s.n)
        return Sparse(0,0,0);
    Sparse *sum = new Sparse(m,n,num+s.num);
    i=j=k=0;
    while (i<num && j<s.num)
    {
        if(elements[i].i<s.elements[j].i)
            sum->elements[k++]=elements[i++];
        else if(elements[i].i>s.elements[j].i)
            sum->elements[k++]=s.elements[j++];
        else
            {
                if(elements[i].j<s.elements[j].j)
                    sum->elements[k++]=elements[i++];
                else if (elements[i].j>s.elements[j].j)
                    sum->elements[k++]=s.elements[j++];
                else
                {
                    sum->elements[k]=elements[i];
                    sum->elements[k++].x=elements[i++].x+s.elements[j++].x;
                }
            }
    }
    for(;i<num;i++) sum->elements[k++]=elements[i];
    for(;j<s.num;j++) sum->elements[k++]=s.elements[j];
    sum->num=k;
    return *sum;
}

istream & operator >> (istream &is, Sparse &s)
{
    cout << "Enter non-zero elements ";
    for(int i=0;i<s.num;i++)
    {
        cin >> s.elements[i].i >> s.elements[i].j >> s.elements[i].x;
    }
    return is;
}

ostream & operator << (ostream &os, Sparse &s)
{
    int k = 0;
    for (int i=0; i< s.m; i++)
    {
        for (int j= 0; j< s.n; j++)
        {
            if (s.elements[k].i==i && s.elements[k].j==j)
                cout<<s.elements[k++].x<<" ";
            else   
                cout<<"0 ";
        }
        cout << endl;
    }
    return os;
}


int main()
{
    Sparse s1(5,5,5);
    Sparse s2(5,5,5);

    cin>>s1;
    cin>>s2;

    Sparse sum = s1+s2;
    cout<<"First Matrix" << endl << s1;
    cout << "Second Matrix" << endl << s2;
    cout << "Sum Matrix" << endl << sum;
    return 0;
}