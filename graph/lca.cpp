// Stolen from http://codeforces.com/blog/entry/16221
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define MAXN 1003
#define MAXLOG 20
#define vi vector <int>
#define vvi vector <vi>

int n, m, u, v, q;
vi h;
vvi adj;

int par[MAXN][MAXLOG]; // initially all -1
void dfs(int v,int p = -1){
	par[v][0] = p;
	if(p + 1)
		h[v] = h[p] + 1;
	for(int i = 1;i < MAXLOG;i ++)
		if(par[v][i-1] + 1)
			par[v][i] = par[par[v][i-1]][i-1];
	for(auto u : adj[v])	if(p - u)
		dfs(u,v);
}

int LCA(int v,int u){
	if(h[v] < h[u])
		swap(v,u);
	for(int i = MAXLOG - 1;i >= 0;i --)
		if(par[v][i] + 1 and h[par[v][i]] >= h[u])
			v = par[v][i];
	// now h[v] = h[u]
	if(v == u)
		return v;
	for(int i = MAXLOG - 1;i >= 0;i --)
		if(par[v][i] - par[u][i])
			v = par[v][i], u = par[u][i];
	return par[v][0];
}

int main() {
    int tc, t=1;
    cin >> tc;
    while (tc--) {
        cin >> n;
        adj = vvi(n+1);
        h = vi(n+1);
        h[1] = 0;
        for (int u = 1; u <= n; u++) {
            cin >> m;
            while (m--) {
                cin >> v;
                adj[u].pb(v);
                h[v] = h[u]+1;
            }
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < MAXLOG; j++) {
                par[i][j] = -1;
            }
        }
        dfs(1);
        cin >> q;
        cout << "Case " << t++ << ":\n";
        while (q--) {
            cin >> u >> v;
            cout << LCA(u, v) << endl;
        }
    }

    return 0;
}
