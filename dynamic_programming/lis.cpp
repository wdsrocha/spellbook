#include "./../template.h"

int n;
vi v;

int index(vi& v, int lo, int hi, int x) {
    while (hi-lo > 1) {
        int m = lo + (hi-lo)/2;
        if (v[m] >= x) {
            hi = m;
        } else {
            lo = m;
        }
    }
    return hi;
}

int lis() {
    vi tail(n);
    int m = 1;
    tail[0] = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] < tail[0]) {
            tail[0] = v[i];
        } else if (v[i] > tail[m-1]) {
            tail[m++] = v[i];
        } else {
            int idx = index(tail, -1, m-1, v[i]);
            tail[idx] = v[i];
        }
    }
    return m;
}
