#include <iostream>

using namespace std;

struct Node

{

    int col, val;

    Node *next;

};

struct SparseMatrix

{

    int n, m, nz;

    Node **ptr;

};

void create(SparseMatrix *s)

{

    cout << "Enter the No of rows:\n";

    cin >> s->n;

    cout << "Enter the No of columns:\n";

    cin >> s->m;

    cout << "Enter the No of non-zero elements:\n";

    cin >> s->nz;

    s->ptr = new Node *[s->n];

    for (int i = 0; i < s->n; i++)

    {

        s->ptr[i] = NULL;

    }

    for (int i = 0; i < s->nz; i++)

    {

        cout << "Enter the row:\n";

        int row;

        cin >> row;

        cout << "Enter the column:\n";

        int column;

        cin >> column;

        cout << "Enter the Element:\n";

        int data;

        cin >> data;

        Node *t = new Node();

        t->val = data;

        t->next = NULL;

        t->col = column;

        if (s->ptr[row] == NULL)

        {

            s->ptr[row] = t;

        }

        else

        {

            Node *p = s->ptr[row];

            while (p->next)

            {

                p = p->next;

            }

            p->next = t;

        }

    }

}



void display(SparseMatrix s)

{

    for (int i = 0; i < s.n; i++)

    {

        Node *p = s.ptr[i];

        for (int j = 0; j < s.m; j++)

        {

            if (p && p->col == j)

            {

                cout << p->val << " ";

                if (p->next)

                    p = p->next;

            }

            else

            {

                cout << "0 ";

            }

        }

        cout << "\n";

    }

}

int main()
{
    SparseMatrix s;
    create(&s);
    display(s);
    return 0;
}