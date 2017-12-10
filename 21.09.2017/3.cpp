#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int *p = a; p < a+n; p++)
        cin >> *p;
    for(int i = 0; i < n; i++){
        for(int *p = a; p < a+n-1; p++){
            if(*(p+1) < *p){
                int t = *p;
                *p = *(p+1);
                *(p+1) = t;
            }
        }
    }
    for(int *p = a; p < a+n; p++)
        cout << *p;
    return 0;
}
