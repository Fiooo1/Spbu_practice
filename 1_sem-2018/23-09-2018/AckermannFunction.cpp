#include<iostream>

using namespace std;

int Akkerman(int m, int n)
{
    if(m == 0)
        return n+1;
    else if( (n == 0) && (m > 0) )
        return Akkerman(m-1, 1);
    else
        return Akkerman(m-1, Akkerman(m, n-1));
}


int main()
{
    int m, n;
    cin >> m;
    cin >> n;
    cout << Akkerman(m, n);
    return 0;
}
