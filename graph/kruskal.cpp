#include "./../template.h"

int n, m;

struct Edge {
    int u, v;
    double w;
};

vi p, sz;
vector <Edge> e;

void init() {
    vi p, sz;
    for (int i = 0; i <= n; i++) {
        p.pb(i);
        sz.pb(1);
    }
}

int find(int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
}

bool join(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) {
        return false;
    }

    if (sz[u] < sz[v]) {
        swap(u, v);
    }
    
}
    

int kruskal() {
    int ans = 0;
    for (int i = 0, j = 1; i < n && j < m; i++) {
        int u = e[i].u;
        int v = e[i].v;
        double w = e[i].w;
        if (join(u, v)) {
            ans += w;
    }
    return ans;
}

