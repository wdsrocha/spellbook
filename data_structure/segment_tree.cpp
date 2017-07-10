// http://wcipeg.com/problem/segtree

#include <bits/stdc++.h>
using namespace std;

#define INF ((int)1e9)
#define MAX 100010

int n, q, a[MAX], t[4*MAX];

int build(int u, int l, int r) {
    if (l == r) {
        return t[u] = a[l];
    } 

    build(2*u, l, (l+r)/2);
    build(2*u+1, (l+r)/2+1, r);
    return t[u] = min(t[2*u], t[2*u+1]);
}

int query(int u, int l, int r, int i, int j) {
    // 1. [l,r] está totalmente fora de [i, j]
    if (r < i or l > j) {
        return INF;
    }

    // 2. [l,r] está dentro de [i, j]
    if (l >= i and r <= j) {
        return t[u];
    }

    // 3. [l, r] está parcialmente em [i, j]
    int lside = query(2*u, l, (l+r)/2, i, j);
    int rside = query(2*u+1, (l+r)/2+1, r, i, j);
    return min(lside, rside);
}

int update(int u, int l, int r, int target, int value) {
    if (l == r) {
        return t[u] = value;
    }

    if (target <= (l+r)/2) {
        update(2*u, l, (l+r)/2, target, value);
    } else {
        update(2*u+1, (l+r)/2+1, r, target, value);
    }
    
    return t[u] = min(t[2*u], t[2*u+1]);
}

int main() {
    while (cin >> n >> q) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        build(1, 0, n-1);
        while (q--) {
            char cmd;
            int i, j;
            cin >> cmd >> i >> j;
            if (cmd == 'Q') {
                cout << query(1, 0, n-1, i, j) << endl;
            } else {
                update(1, 0, n-1, i, j);
            }
        }
    }

    return 0;
}
