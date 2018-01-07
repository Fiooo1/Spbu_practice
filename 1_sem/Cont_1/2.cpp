#include<iostream>

using namespace std;

int del(int *&p, int Size)
{
    int x = 0;
    for(int i = 0; i < Size; i++){
        int k = 0;
        for(int j = 2; j < *(p+i); j++){
            if(*(p+i) % j == 0)
               k+=1;
        }
        if(k != 1)
            x+=1;
    }
    int * m = new int[x];
    int y = 0;
    for(int i = 0; i < Size; i++){
        int k = 0;
        for(int j = 2; j < *(p+i); j++){
            if(*(p+i) % j == 0)
               k+=1;
        }
        if(k != 1){
            m[y] = *(p+i);
            y+=1;
        }
    }
    delete[] p;
    p = m;
    return x;
}
