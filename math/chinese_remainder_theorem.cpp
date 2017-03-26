#include "../template.h"

int f(int value, int mod) {
	int ans = 0;
	while ((ans * value) % mod != 1)
		ans++;
	return ans;
}

signed main() {
	int n;
	cin >> n;
	vi a(n), m(n);
	int P = 1;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> m[i];
		P *= m[i];
	}
	
	int x = 0;
	for (int i = 0; i < n; i++) {
		int p = P / m[i];
		int q = p % m[i];
		int r = f(q, m[i]);
		int s = a[i]*p*r;
		x = (x + s % P) % P;
	}
	if (!x) x = P;

	cout << x << endl;

	return 0;
}
