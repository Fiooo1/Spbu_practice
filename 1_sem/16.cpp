#include <iostream>

using namespace std;

struct node
{
    int x;
    node *next;
};

class Queue
{
    node *first, *last;
public:
     Queue(): first(NULL), last(NULL){};
     ~Queue()
     {
          node *temp = first;
          while (temp!=NULL)
          {
              temp = first->next;
              delete first;
              first = temp;
          }
     }


     void add(int x)
     {
          node *temp = new node;
          temp->x = x;
          temp->next = NULL;
          if (first!=NULL)
          {
              last->next = temp;
              last = temp;
          }
          else first = last = temp;
     }


     void show()
     {
          node *temp = first;
          while (temp!=NULL)
          {
              cout << temp->x << " ";
              temp = temp->next;
          }
          cout << endl;
     }


     void del()
     {
          if (first != NULL)
          {
              node *temp = first;
              cout<< "Element " << first->x <<" has been deleted" << endl;
              first = first->next;
              delete temp;
          }
     }
};


int main()
{
   Queue q;
   for(int i = 1; i < 11; i++) q.add(i);
   q.show();
   q.del();
   q.show();
   return 0;
}
