#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void test_case(int& tc) {
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll ans = 0, sum = 0;
	for (int i = -1; i < n; i++) {
		ll now = sum;
		for (int j = i + 1; j < min(n, i + 32); j++) {
			int copy = a[j];
			copy >>= j - i;
			now += copy;
		}
		ans = max(ans, now);
		if (i + 1 != n) {
			sum += a[i+1] - k;
		}
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T = 1;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		test_case(tc);
	}
}
