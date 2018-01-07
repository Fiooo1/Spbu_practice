#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int x1;
    int x2;
    int y1;
    int y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int x = abs(x1-x2); y = abs(y1-y2);
    int a[x][y];
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++)
            cin >> a[i][j];
    }
    for(int i = 1; i < y; i++)
        a[0][i] = a[1][1];
    for(int i = 1; i < x; i++)
        a[i][0] = a[1][0];
    for(int i = 1; i < y; i++){
        for(int j = 1; j < x; j++){
                a[i][j] += a[i-1][j-1] + a[i-1][j] + a[i]{j-1} - 1;
                a[j][i] += a[i-1][j-1] + a[i-1][j] + a[i]{j-1} - 1;
        }

    }
    cout << a[x-1][y-1];
}
