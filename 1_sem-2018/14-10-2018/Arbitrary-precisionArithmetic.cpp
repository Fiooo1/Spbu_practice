#include <iostream>
using namespace std;
const int maxsize = 100;
 
void cinlong(int *mas) 
{
    string s;
    cin >> s;
    for(int i=0;i<maxsize;++i)
        mas[i] = 0;
 
    for(int i=0;i<s.length();i++)
    mas[s.length() - i] = int(s[i]) - 48;  
}
 
void coutlong(int *mas) 
{
    int i = maxsize;
    while(mas[i] == 0 && i > 1) i--;  
 
    for(int j=i;j>=1;j--)
        cout << mas[j];
}

int summ(int *a, int *b)
{
	 int c = 0;
    for(int i=1;i<maxsize;++i)
    {
	    c = c + a[i] + b[i],
        a[i] = c % 10,
        c /= 10;
    }

    
}
int main()
{
    int a[maxsize], b[maxsize];
 
    cinlong(a);
    cinlong(b);
    summ(a,b);
    coutlong(a);
}
