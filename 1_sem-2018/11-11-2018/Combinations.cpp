#include <iostream>
using namespace std;
int main()
{
int n=5; 
int k=2;
int C[n][k];

int B[n+1][n+1]; 
for(int i=0;i<=n;++i) 
{
B[i][0]=1; 
B[i][i]=1;
for(int j=1;j<i;++j)
  { 
  B[i][j]=B[i-1][j-1]+B[i-1][j];
  }
}


cout<<B[n][k];
}
