#include <iostream>

using namespace std;

struct List
{
    int x;
    List *next,*first;
};

void Add(int x, List *&MyList)
{
    List *temp = new List;
    temp->x = x;
    temp->next = MyList->first;
    MyList->first = temp;
}


void Show(List *MyList)
{
    List *temp = MyList->first;
    while (temp!=NULL) {
         cout << temp->x << " ";
         temp = temp->next;
    }
}


void ClearList(List *MyList)
{
    while (MyList->first != NULL){
         List *temp = MyList->first->next;
         delete MyList->first;
         MyList->first = temp;
    }
}

int main()
{
    int n;
    cin >> n;
    List *MyList = new List;
    MyList->first = NULL;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        Add(x, MyList);
    }
    Show(MyList);
    ClearList(MyList);
    delete MyList->first;
    delete MyList;
}
