// https://csacademy.com/contest/archive/#task/xor-closure
#include "../template.h"

int lsb(int x) { return x & -x; }

signed main() {
	int n;
	set <int> numbers;
	cin >> n;
	vi a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		numbers.insert(a[i]);
	}

	map <int, int> base;
	base[0] = 0;
	for (auto k : a) {
		while (base[lsb(k)])
			k ^= base[lsb(k)];
		base[lsb(k)] = k;
	}
	
	int base_count = base.size() - 1;
	int subset_count = (1LL << base_count);
	int ans = subset_count - numbers.size();

	cout << ans << endl;
	
	return 0;
}
