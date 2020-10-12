#include <cstdlib>
#include <iostream>

const int data_size = 10001;

//bst__begin
typedef struct _tnode
{
    _tnode *Lchild;
    _tnode *Rchild;
    int Value;
} tnode;
tnode Node[data_size];
int bst_count = 0;

void bst_insert(tnode *&r, int value)
{
    if (!r)
    {
        r = &Node[bst_count++];
        r->Value = value;
        r->Lchild = NULL;
        r->Rchild = NULL;
    }
    else if (value < r->Value)
    {
        bst_insert(r->Lchild, value);
    }
    else
    {
        bst_insert(r->Rchild, value);
    }
}

void bst_post(tnode *r)
{
    if (r)
    {
        bst_post(r->Lchild);
        bst_post(r->Rchild);
        cout << r->Value << endl;
    }
}
//bst__end

int data[data_size];

int main()
{
    int size = 0;
    while (cin >> &data[size])
    {
        size++;
    }
    if (size)
    {
        tnode *bst_root = NULL;
        for (int i = 0; i < size; ++i)
        {
            bst_insert(bst_root, data[i]);
        }
        bst_post(bst_root);
    }

    return 0;
}
