#include <iostream>
#include <cstdio>

using namespace std;

struct node
{
    int x;
    node *next;
    node *prev;
};

class dequeue
{
    node *first, *last;
public:
    dequeue(): first(NULL), last(NULL){};
    ~dequeue()
    {
        node *temp = first;
        while (temp != NULL)
        {
            temp = first->next;
            delete first;
            first = temp;
        }
    }


    void show()
    {
        node *temp = first;
        while (temp != NULL)
        {
            cout << temp->x << " ";
            temp = temp->next;
        }
        cout << endl;
    }


    void AddRight(int x)
    {
        node *temp = new node;
        node *t = last;
        temp->x = x;
        temp->next = NULL;
        if (first != NULL)
        {
            last->next = temp;
            last = temp;
            last->prev = t;
        }
        else first = last = temp;
    }


    void AddLeft(int x)
    {
        node *temp = new node;
        node *t = first;
        temp->x = x;
        temp->prev = NULL;
        if(last != NULL)
        {
            first->prev = temp;
            first = temp;
            first->next = t;
        }
        else
        {
            first = last = temp;
            temp->next = NULL;
        }
    }


    void DelRight()
    {
        if(last != NULL)
        {
            node *temp = last;
            cout<< "Element " << last->x <<" has been deleted" << endl;
            last = last->prev;
            last->next = NULL;
            delete temp;
        }
    }


    void DelLeft()
    {
        if(first != NULL)
        {
            node *temp = first;
            cout<< "Element " << first->x <<" has been deleted" << endl;
            first = first->next;
            first->prev = NULL;
            delete temp;
        }
    }
};


int main()
{
    dequeue d;
    for(int i = 1; i < 6; i++) d.AddRight(i);
    for(int i = 6; i < 11; i++) d.AddLeft(i);
    d.show();
    d.DelLeft();
    d.show();
    d.DelRight();
    d.show();
    return 0;
}
