#include <cstdio>
#include <iostream>

using namespace std;

void print(int d) {
	for (int r = d; r < 10; ++r)
		for (int c = 0; c < 10; ++c)
			for (int b = 0; b < 10; ++b)
				for (int g = 0; g + b < 10 - (c + d) % 10; ++g)
					for (int a = 0; a < 10; ++a){
						cout << a << b << c << 5 << d << endl;
						cout << 0 << g << d << d << r << endl;
						cout << a << b+g << c << 5 << (d+r) % 10 << endl;
						cout << endl;
					}
}

int main() {
	print(0);
	print(9);
	return 0;
}
