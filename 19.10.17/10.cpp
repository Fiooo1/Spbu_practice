#include<iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    if(k>n)
        k = n;
    int a[k+1];
    a[0] = 1; a[1] = 1;
    for(int i = 2; i <= k; i++)
        a[i] = 0;
    for(int i = 2; i <= k; i++){
        for(int j = 1; j <= k; j++){
            if(i-j > -1)
               a[i] += a[i-j];
        }
    }
    for(int i = 0; i <= k; i++)
        cout << a[i] << " ";
    cout << endl;
    for(int i = k; i < n; i++){
        int y = a[k];
        for(int j = 1; j < k; j++)
            a[k] += a[k-j];
        for(int h = 0; h < k; h++){
            a[h] = a[h+1];
        }
        a[k-1] = y;
        for(int i = 0; i <= k; i++)
            cout << a[i] << " ";
        cout << endl;
    }
    cout << a[k];
}
