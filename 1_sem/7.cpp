#include<iostream>

using namespace std;

int main()
{
    int a, p;
    cin >> a;
    cin > p;
    int e = 0, s = p - 1;
    while (s % 2 == 0)
    {
        e += 1;
        s /= 2;
    }
    cout << "e" << " " << "=" << " " << e << endl;
    cout << "s" << " " << "=" << " " << s << endl;
    int z;
    bool f;
    for (z = 2; z < p; z++){
        f = false;
        for (int j = 1; !f && j < p; j++)
                f |= j * j % p == z;
        if (!f)
            break;
    }
    cout << "z" << " " << "=" << " " << z << endl;
    unsigned int t = a, y = a, i, b, c = z, n = e, con = 0;
    for (int i = 1; i < (s+1) / 2; i++){
        y *= a;
        y %= p;
    }
    cout << "y" << " " << "=" << " " << y << endl;
    for (int i = 1; i < s; i++){
        c *= z;
        c %= p;
        t *= a;
        t %= p;
    }
    cout << "c" << " " << "=" << " " << c << endl;
    cout << "t" << " " << "=" << " " << t << endl;
    if (e == 1){
        int x = a;
        for (int i = 1; i < (p+1) / 4; i++){
             x *= a;
             x %= p;
        }
        cout << "x" << " " << "=" << x << endl;
        cout << "x" << " " << "=" << p - x;
    }
    else{
        while (t != 1){
            i = 0;
            con += 1;
            unsigned int f = t;
            while (f != 1){
                i+=1;
                f = t;
                for (int j=0; j<i; j++){
                    f = f*f;
                    f %= p;
                }
            }
            cout << "i" << con << " " << "=" << " " << i << endl;
            b = c;
            for (int j = 0; j < n - 1 - i; j++)
                b = c*c % p;
            y = y*b % p;
            t = t*b*b % p;
            n = i;
            c = b*b % p;
            cout << "b" << con << " " << "=" << " " << b << endl;
            cout << "y" << con << " " << "=" << " " << y << endl;
            cout << "t" << con << " " << "=" << " " << t << endl;
            cout << "n" << con << " " << "=" << " " << n << endl;
            cout << "c" << con << " " << "=" << " " << c << endl;
        }
    cout << "y" << con << " " << "=" << " " << y << " - reshenie" << endl;
    }
}
