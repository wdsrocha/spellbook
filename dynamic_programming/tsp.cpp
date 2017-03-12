#include "../template.h"

int n;
vi pred;
vvd dist, memo;

double tsp(int u, int mask) {
	if (mask == (1 << n) - 1) return dist[u][0];
	if (memo[u][mask] != -1) return memo[u][mask];
	double best = INF;
	for (int v = 0; v < n; v++) {
		if (!(mask & (1 << v))) {
			double cur = tsp(v, mask | (1 << v)) + dist[u][v];
			if (cur < best) {
				best = cur;
				pred[u] = v;
			}
		}
	}
	return memo[u][mask] = best;
}

double tspCall() {
	pred = vi(n);
	memo = vvd(n, vd((1 << n)));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < (1 << n); j++)
			memo[i][j] = -1;
	return tsp(0, 1);
}

vi printPath() {
	vi path;
	int u = 0;
	for (int i = 0; i < n; i++) {
		path.pb(pred[u]);
		u = pred[u];
	}
	return path;
}
