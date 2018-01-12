#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN(1e5);

bool lss(pair <int, int> &a, pair <int, int> &b)
	{ return (double)a.second / a.first > (double)b.second / b.first; }


int main() {
	int n, w;
	pair <int, int> t[MAXN];
	cin >> n >> w;
	for (int i(0); i < n; ++i)
		cin >> t[i].first >> t[i].second;
	sort(t, t + n, &lss);
	double ans(0);
	for (int i(0); w && i < n; ++i)
		if (w >= t[i].first)
			w -= t[i].first, ans += t[i].second;
		else {
			ans += (double)w / t[i].first * t[i].second;
			break;
		}
	cout << ans;
	return 0;
}
