// https:www.urionlinejudge.com.br/judge/pt/problems/view/1500

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF ((int)1e9)
#define MAX 100010
#define DEFAULT 0

int n, q, a[MAX], tree[4*MAX], lazy[4*MAX];

void build(int u, int l, int r) {
    lazy[u] = DEFAULT;
    if (l == r) {
        tree[u] = a[l];
        return;
    } 
    build(2*u, l, (l+r)/2);
    build(2*u+1, (l+r)/2+1, r);
    tree[u] = tree[2*u] + tree[2*u+1];
}

void propagate(int u, int l, int r) {
    if (lazy[u] != DEFAULT) {
        tree[u] += (r-l+1)*lazy[u];
        if (l != r) {
            lazy[2*u] += lazy[u];
            lazy[2*u+1] += lazy[u];
        }
        lazy[u] = DEFAULT;
    }
}

int query(int u, int l, int r, int i, int j) {
    propagate(u, l, r);
    if (r < i or l > j) {
        return 0;
    }
    if (l >= i and r <= j) {
        return tree[u];
    }
    int lside = query(2*u, l, (l+r)/2, i, j);
    int rside = query(2*u+1, (l+r)/2+1, r, i, j);
    return lside + rside;
}

void updateRange(int u, int l, int r, int i, int j, int value) {
    propagate(u, l, r);
    if (l > r or r < i or l > j) {
        return;
    }
    if (l >= i and r <= j) {
        tree[u] += (r-l+1)*value;
        if (l != r) {
            lazy[2*u] += value;
            lazy[2*u+1] += value;
        }
        return;
    }
    updateRange(2*u, l, (l+r)/2, i, j, value);
    updateRange(2*u+1, (l+r)/2+1, r, i, j, value);
    tree[u] = tree[2*u] + tree[2*u+1];
}

signed main() {
    int t, cmd, i, j, x;
    cin >> t;
    while (t--) {
        cin >> n >> q;
        build(1, 1, n);
        while (q--) {
            cin >> cmd >> i >> j;
            if (cmd) {
                cout << query(1, 1, n, i, j) << endl;
            } else {
                cin >> x;
                updateRange(1, 1, n, i, j, x);
            }
        }
    }
    return 0;
}
