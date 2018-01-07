#include <iostream>
using namespace std;

struct String {
	char *st;
	int l;
	String(char *s) {
		int i;
		for (i = 0; s[i]; ++i) {
          l = i;
		}
		st = new char[i + 1];
		for (i = 0; s[i]; ++i) {
			st[i] = s[i];
		}
		st[i] = '\0';
	}
	void getlength() {
		cout << l+1 << endl;;
	}
	void out() {
		for (int i = 0; st[i]; ++i)
			cout << st[i];
	}
	void put(int n, char ch) {
		if (n < l &&n >=0 )
			st[n] = ch;
	}
	~String() {
		delete[] st;
	}
};

int main() {
	char *f=new char;
	cin >> f;
	String st(f);
	st.getlength();
	st.put(1, '?');
	st.out();
	return 0;
}
