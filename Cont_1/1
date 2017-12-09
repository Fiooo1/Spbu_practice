#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n][n];
    if(n%2 == 0){
            for(int i = 0; i < n/2; i++){
                for(int j = 0; j < n/2-i; j++){
                    a[i][j+i] = n/2 - j;
                    a[i][n-j-1-i] = n/2 - j;
                    a[j+i][i] = n/2 - j;
                    a[n-j-1-i][i] = n/2 - j;
                    a[j+i][n-i-1] = n/2 - j;
                    a[n-j-1-i][n-i-1] = n/2 - j;
                    a[n-i-1][j+i] = n/2 - j;
                    a[n-i-1][n-j-1-i] = n/2 - j;
                }
           }
    }
    else{
            a[n/2][n/2] = n/2 + 1;
            for(int i = 0; i < n/2; i++){
                for(int j = 0; j <= n/2-i; j++){
                    a[i][j+i] = n/2 + 1 - j;
                    a[i][n-j-1-i] = n/2 + 1 - j;
                    a[j+i][i] = n/2 + 1 - j;
                    a[n-j-1-i][i] = n/2 + 1 - j;
                    a[j+i][n-i-1] = n/2 + 1 - j;
                    a[n-j-1-i][n-i-1] = n/2 + 1 - j;
                    a[n-i-1][j+i] = n/2 + 1 - j;
                    a[n-i-1][n-j-1-i] = n/2 + 1 - j;
                }
           }

    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << a[i][j];
        cout << endl;
    }
}
