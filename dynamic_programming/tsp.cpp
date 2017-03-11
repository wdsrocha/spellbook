#include "../template.h"

int n;
vvi dist, memo;

double tsp(int u, int mask)
{
	if (mask == (1 << n) - 1) return dist[u][0];

	if (memo[u][mask] != -1) return memo[u][mask];

	double best = INF;
	for (int v = 0; v < n; v++)
		if (!(mask & (1 << v)))
			best = min(best, tsp(v, mask | (1 << v)) + dist[u][v]);

	return memo[u][mask] = best;
}

double tspCall()
{
	memo = vvi(n, vi((1 << n)));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < (1 << n); j++)
			memo[i][j] = -1;

	return tsp(0, 1);
}
