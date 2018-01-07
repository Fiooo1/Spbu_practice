#include<iostream>
#include <cstdio>

using namespace std;

class Q
{
    private:
        int n, m;
        int gcd(int a, int b)
        {
            if((a>b) && (a%b == 0))
                return b;
            else if((b>a) && (b%a == 0))
                return a;
            else if(a>b)
                return gcd(a%b, b);
            else if(b>a)
                return gcd(a, b%a);
            else
                return a;
        }
        int lcm(int a, int b)
        {
            return a*b / gcd(a, b);
        }
        void norm()
        {
            int x = gcd(n, m);
            n /= x;
            m /= x;
        }
    public:
        Q(int a, int b)
        {
            n = a; m = b;
            norm();
            if(m<0)
                m *= -1, n *= -1;
        }
        void print()
        {
            if(m == 1)
                cout << n;
            else
                cout << n << "/" << m;
        }
        Q operator+(const Q sec){
            int x = lcm(m, sec.m);
            return Q(n*(x/m) + sec.n*(x/sec.m), lcm(m, sec.m));
        }
        Q operator-(const Q sec){
            int x = lcm(m, sec.m);
            return Q(n*(x/m) - sec.n*(x/sec.m), lcm(m, sec.m));
        }
        Q operator*(const Q sec){
            return Q(n*sec.n, m*sec.m);
        }
        Q operator/(const Q sec){
            return Q(n*sec.m, m*sec.n);
        }
};
