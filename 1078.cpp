#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 1000005;
vector<int> SUM(maxn << 2);
vector<int> lazy(maxn << 2);

void lazyDown(int rt, int Len) {
    if (lazy[rt]) {
        lazy[rt << 1] = lazy[rt << 1 | 1] = lazy[rt];
        SUM[rt << 1] = (Len - (Len >> 1)) * lazy[rt];
        SUM[rt << 1 | 1] = (Len >> 1) * lazy[rt];
        lazy[rt] = 0;
    }
}

void build(int l, int r, int rt) {
    lazy[rt] = 0;
    if (l == r) {
        scanf("%d", &SUM[rt]);
    } else {
        const int m = l + (r - l) / 2;
        build(l, m, rt << 1);
        build(m + 1, r, rt << 1 | 1);
        SUM[rt] = SUM[rt << 1] + SUM[rt << 1 | 1];
    }
}

void update(int L, int R, int val, int l, int r, int rt) {
    if (L <= l && r <= R) {
        lazy[rt] = val;
        SUM[rt] = val * (r - l + 1);
    } else {
        lazyDown(rt, r - l + 1);
        const int m = l + (r - l) / 2;
        if (L <= m) update(L, R, val, l, m, rt << 1);
        if (R > m) update(L, R, val, m + 1, r, rt << 1 | 1);
        SUM[rt] = SUM[rt << 1] + SUM[rt << 1 | 1];
    }
}

int query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) return SUM[rt];
    lazyDown(rt, r - l + 1);
    const int m = l + (r - l) / 2;
    int ret = 0;
    if (L <= m) ret += query(L, R, l, m, rt << 1);
    if (R > m) ret += query(L, R, m + 1, r, rt << 1 | 1);
    return ret;
}

int main() {
    int N, Q;
    scanf("%d", &N);
    build(1, N, 1);
    scanf("%d", &Q);
    int op, Li, Ri, NewP;
    while (Q--) {
        scanf("%d", &op);
        if (op) {
            scanf("%d %d %d", &Li, &Ri, &NewP);
            update(Li, Ri, NewP, 1, N, 1);
        } else {
            scanf("%d %d", &Li, &Ri);
            printf("%dn", query(Li, Ri, 1, N, 1));
        }
    }
    return 0;
}