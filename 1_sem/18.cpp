#include<iostream>
#include<algorithm>

using namespace std;

struct node
{
    int x;
    node *next, *prev;
};


class List
{
    node *first, *last;
public:
    List(): first(NULL), last(NULL){};
    ~List()
    {
        while(first != NULL)
        {
            last = first->next;
            delete first;
            first = last;
        }
    }


    void add(int x)
    {
        node *temp = new node;
        temp->next = NULL;
        temp->x = x;
        if (first != NULL)
        {
            temp->prev = last;
            last->next = temp;
            last = temp;
        }
        else
        {
            temp->prev = NULL;
            first = last = temp;
        }
    }


    void show()
    {
        node *temp = last;
        while (temp != NULL)
        {
            cout << temp->x << " ";
	        temp = temp->prev;
        }
        cout << endl;

        temp = first;
        while (temp != NULL)
        {
            cout << temp->x << " ";
	        temp = temp->next;
        }
        cout << endl;

    }


    void Sort()
    {
        for(node *i = first; i->next != NULL; i = i->next){
                for(node *j = first; j->next != NULL; j = j->next){
                        if(j->x > j->next->x)
                            swap(j->x, j->next->x);

                }
        }
    }
};


int main()
{
    List l;
    l.add(5);
    l.add(2);
    l.add(7);
    l.add(1);
    l.show();
    cout << endl;
    l.Sort();
    l.show();
    return 0;
}
