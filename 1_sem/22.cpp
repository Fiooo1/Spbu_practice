#include <iostream>

using namespace std;
struct node {
	int data;
	node *left, *right;
};


struct tree {
	node *first = NULL;
	node *push(int l, int r,int *a) {
	 node* temp = new node();
	 if (l > r)
	 	return NULL;
	 temp->data = a[(l + r) / 2];
	 temp->right = push((l + r) / 2 + 1, r, a);
	 temp->left = push(l, (l + r) / 2 - 1, a);
	 return temp;
    }
	void show(node *first) {
		if (first != NULL) {
			show(first->left);
			cout << first->data;
			show(first->right);
		}
	}
	void del(node *Tree) {
		if (Tree != NULL) {
			del(Tree->left);
			del(Tree->right);
			delete Tree;
		}
	}
};
