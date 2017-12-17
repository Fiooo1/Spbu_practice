#include<iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    cin >> n;
    int a[n*n];
    for(int i = 0; i < n*n; i++)
        cin >> a[i];
    int k, m;
    cout << "Введите номер строки" << endl;
    cin >> k;
    cout << "Введите номер столбца" << endl;
    cin >> m;
    cout << a[n*k + m];
    return 0;
}
