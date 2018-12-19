#include <iostream>
#include <cmath>
using namespace std;
int main()
{
int n,i,j,k;
cout<<"Vvedite kol-vo yravnenii"<<endl;
cin>>n;
double a[n+1][n+1];
int c[n+1];
double x[n+1];
double g,r;
for (i=1; i<=n; i++)
{
	cout<<"Vvedite koefficenti pri x1,x2,x3,...,xn "<<i<<"-ogo virazeniya"<<endl;
	for (j=1; j<=n; j++)
	{
		cin>>a[i][j];
	}
	cout<<"Vvedite znachenie C "<<endl;
	cin>>c[i];
}
for (k=1; k<=n; k++)
{
	for (j=k+1; j<=n; j++)
	{
	r=a[j][k]/a[k][k];
	for (i=k;i<=n; i++)
	{
		a[j][i]-=r*a[k][i];
    }
    c[j]+=-r*c[k];
    }	
}

for (k=n;k>=1;k--)
{
	r=0;
	for (j=k+1; j<=n; j++)
	{
		g=a[k][j]*x[j];
		r=r+g;
	}
	x[k]=(c[k]-r)/a[k][k];
}
for (i=1;i<=n; i++)
{
	cout<<x[i]<<" ";
}
}
