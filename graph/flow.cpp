#include "./../template.h"

struct Hash {
	size_t operator()(const ii& x) const {
		return hash <int>()(x.fi^(x.se << 32));
	}
};

vi pred;
vvi adj;
unordered_map <ii, int, Hash> edges;

bool bfs(int src, int dest) {
	queue <int> q;
	q.push(src);
	vi vis(SZ(adj));
	vis[src] = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (u == dest) return 1;
		for (int j = 0; j < SZ(adj[u]); j++) {
			int v = adj[u][j];
			if (!vis[v] && edges[ii(u, v)]) {
				pred[v] = u;
				vis[v] = 1;
				q.push(v);
			}
		}
	}
	return 0;
}

int sendFlow(int s, int t) {
	int flow = INF;
	for (int i = t; i != s; i = pred[i]) {
		int capacity = edges[ii(pred[i], i)];
		flow = min(flow, capacity); 
	}
	for (int i = t; i != s; i = pred[i]) {
		edges[ii(pred[i], i)] -= flow;
		edges[ii(i, pred[i])] += flow;
	}
	return flow;
}

int maxFlow(int s, int t) {
	int max_flow = 0;
	while (bfs(s, t)) {
		max_flow += sendFlow(s, t);
	}
	return max_flow;
}

void init(int n) {
	pred = vi(n);
	adj = vvi(n);
	edges.clear();
}

void addEdge(int u, int v, int w = 1) {
	adj[u].eb(v);
	adj[v].eb(u);
	edges[ii(u, v)] = w;
	edges[ii(v, u)] = u;
}

signed main() {
	int n, m;
	cin >> n >> m;
	init(n);
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		addEdge(u, v, w);
	}
	int s, t;
	cin >> s >> t;
	cout << maxFlow(s, t) << endl;

	return 0;
}
