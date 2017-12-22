#include<iostream>
#include<cmath>

using namespace std;

int const N = 3;

int foo(int a[N], int first, int last)
{
    if(first == last - 1)
    if(first == last)
        return a[first];
    else
        return ( pow(foo(a, first, last/2), 2) + pow(foo(a, last/2 +1, last), 3) - 18 );
}

int main()
{
    int b[N] = {1, 2, 3};
    cout << foo(b, 0, 2);
    return 0;
}
