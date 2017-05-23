#include "../template.h"

#define MOD MOD7

vvi mul(vvi a, vvi b) {
    int n = a.size();
    int m = b[0].size();
    vvi c(n, vi(m));
    FOR(i,n) FOR(j,m) FOR (k,n)
        c[i][j] = (c[i][j] + a[i][k]*b[k][j]) % MOD;
    return c;
}

vvi pow(vvi b, int e) {
    int n = b.size();
    vvi x(n, vi(n));
    FOR (i,n) x[i][i] = 1;
    for (; e; b=mul(b, b), e>>=1) {
        if (e&1) x = mul(x, b);
    }
    return x;
}

// Fn = T^(n-1)*B
int solve(vvi T, vvi B, int n) {
    return mul(pow(T, n-1), B)[0][0];
}
