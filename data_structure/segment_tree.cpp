// 0 p q v - você tem que adicionar v para todos os números na faixa de p à q (inclusive), onde p e q são dois índices do array.
// 1 p q - imprima uma linha contendo um único inteiro, que é a soma de todos os elementos do array entre p e q (inclusive).

#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);
#define INF ((int)1e9)
#define pb push_back
#define int long long
#define ii pair <int, int>
#define vi vector <int>
#define vii vector <ii>
#define vvi vector <vi>
#define vvii vector <vii>
#define left(x) (2 * x)
#define right(x) (2 * x + 1)
#define mid(a, b) ((a + b) / 2)

int n, m, l, r, x;
vi tree, lazy;

int query(int u = 1, int i = 1, int j = n) {
	if (lazy[u]) {
        if (i != j) {
            lazy[left(u)] += lazy[u];
            lazy[right(u)] += lazy[u];
        }
		tree[u] += (j - i + 1) * lazy[u];
		lazy[u] = 0;
	}

	if (i > r || j < l) return 0;

	if (i >= l && j <= r) return tree[u];

	int p1 = query(left(u), i, mid(i, j));
	int p2 = query(right(u), mid(i, j) + 1, j);

	return p1+p2;
}

int update(int u = 1, int i = 1, int j = n) {
	if (lazy[u]) {
        if (i != j) {
            lazy[left(u)] += lazy[u];
            lazy[right(u)] += lazy[u];
        }
		tree[u] += (j - i + 1) * lazy[u];
		lazy[u] = 0;
	}

	if (i > r || j < l) return tree[u];

	if (i >= l && j <= r) {
        if (i != j) {
            lazy[left(u)] += x;
            lazy[right(u)] += x;
        }
		return tree[u] += (j - i + 1) * x;
	}

	int p1 = update(left(u), i, mid(i, j));
	int p2 = update(right(u), mid(i, j) + 1, j);

	return tree[u] = p1 + p2;
}

signed main() {_
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> m;

		tree = vi(5*n, 0);
		lazy = vi(5*n, 0);

		while (m--) {
			int cmd;
			cin >> cmd >> l >> r;
			if (l > r) swap(l, r);
			if (!cmd) {
				cin >> x;
				update();
			}
			else cout << query() << endl;
		}
	}
	return 0;
}
