#include <cstddef>

using namespace std;

struct node
{
    int key;
    int height;
    node *right;
    node *left;
    node (int k) : key(k), height(1), left(NULL), right(NULL) { }
};


int height(node *p)
{
    if (p) return p->height;
    else return 0;
}


int BF(node *p)
{ return height(p->right)-height(p->left); }


void OverHeight(node *p)
{
    int hleft=height(p->left);
    int hright=height(p->right);
    p->height = (hleft > hright ? hleft : hright)+1;
}


node* RightRotation(node *x)
{
    node *y = x->left;
    x->left = y->right;
    y->right = x;
    OverHeight(x);
    OverHeight(y);
    return y;
}


node *LeftRotation(node *y)
{
    node *x = y->right;
    y->right = x->left;
    x->left = y;
    OverHeight(y);
    OverHeight(x);
    return x;
}

node *Balance(node *x)
{
    OverHeight(x);
    if (BF(x) == 2)
    {
        if (BF(x->right)<0) x->right = RightRotation(x->right);
        return LeftRotation(x);
    }
    if (BF(x) == -2)
    {
        if (BF(x->left)>0) x->left = LeftRotation(x->left);
        return RightRotation(x);
    }
    return x;
}


node *Add (node *x, int k)
{
    if (!x) return new node(k);
    if (k < x->key) x->left = Add(x->left, k);
    else x->right = Add(x->right, k);
    return Balance(x);
}
