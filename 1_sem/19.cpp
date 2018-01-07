#include <iostream>

using namespace std;

struct node
{
    int y;
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


     void add(int x, int y)
     {
          node *temp = new node;
          temp->x = x;
          temp->y = y;
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
          node *t = first;
          for(node *i = first; i != NULL; i = i->next)
            if(i->x > t->x) t = i;
          while (temp!=NULL)
          {
              cout << temp->y << " ";
              temp = temp->next;
          }
          cout << endl;
          cout << t->y << " - max priority";
          cout << endl << endl;
     }




     void del()
     {
          if (first != NULL)
          {
              node *t = first, *tprev = first;
              for(node *i = first; i != NULL; i = i->next)
                if(i->x > t->x)
                {
                    tprev = t;
                    t = i;
                }
              cout << "Element " << t->y <<" has been deleted" << endl;
              tprev->next = t->next;
              delete t;
          }
     }
};


int main()
{
   Queue q;
   for(int i = 1; i < 11; i++) q.add(i, 11 - i);
   q.show();
   q.del();
   q.show();
   return 0;
}
