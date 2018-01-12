#include <cstddef>

using namespace std;

struct node
{
	int key, prior;
	node *left;
	node *right;
	node (int key, int prior) : key(key), prior(prior), left(NULL), right(NULL) { }
};

void split (node t, int key, node & left, node & right)
{
	if (t = nullptr)
		left = right = NULL;
	else if (key < t->key)
		split (t->l, key, left, t->l),  right = t;
	else
		split (t->r, key, t->r, right),  left = t;
}

void Add (node & t, node it)
{
	if (!t)
		t = it;
	else if (it->prior > t->prior)
		split (t, it->key, it->left, it->right),  t = it;
	else
		Add (it->key < t->key ? t->left : t->right, it);
}

void Merge (node & t, node left, node right)
{
	if (!left || !right)
		t = left ? left : right;
	else if (left->prior > right->prior)
		Merge (left->right, left->right, right),  t = l;
	else
		Merge (right->left, left, right->left),  t = right;
}

void Erase (node & t, int key)
{
	if (t->key == key)
		Merge (t, t->left, t->right);
	else
		Erase (key < t->key ? t->left : t->right, key);
}

node unite (node left, node right)
{
	if (!left || !right)  return left ? left : right;
	if (left->prior < right->prior)  swap (left, right);
	node lt, rt;
	split (right, left->key, lt, rt);
	left->left = unite (left->left, lt);
	left->right = unite (left->right, rt);
	return left;
}
