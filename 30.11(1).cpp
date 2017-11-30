#include<iostream>
#include<algorithm> 

using namespace std;


struct node
{
    unsigned x;
    node *left, *right;
};


node* make(int l, int r, unsigned a[])
{
    node* t = new node;
    t->x = a[(l+r)/2];
    t->right = make((l+r)/2 + 1, r, a);
    t->left = make(l, (l+r)/2 - 1, a);
    return t;
}

bool Search(node* tree, unsigned z)
{
    while(tree != NULL)
        if(z == tree->x)
             return true;
        else
            tree = z < tree->x ? tree->left : tree->right;
    return false;
}


int main()
{
    node* root;
    int n;
    cin >> n;
    unsigned a[n], A, B, C, D;
    for(int i = 0; i < n; i++){
        cin >> A >> B >> C >> D; 
        a[i] = A*(1<<24)+B*(1<<16)+C*(1<<8)+D;
    }
    sort(a, a + n);
    root = make(0, n-1, a);
    int m;
    cin >> m;
    unsigned temp;
    for(int i = 0; i < m; i++){
        cin >> A >> B >> C >> D; 
        temp = A*(1<<24)+B*(1<<16)+C*(1<<8)+D;
        cout << Search(root, temp);
    }
    return 0;
}
