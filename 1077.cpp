#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 1000005;
vector<int> MIN(maxn << 2);

void build(int l, int r, int rt) {
    if (l == r) {
        scanf("%d", &MIN[rt]);
    } else {
        const int m = l + (r - l) / 2;
        build(l, m, rt << 1);
        build(m + 1, r, rt << 1 | 1);
        MIN[rt] = min(MIN[rt << 1], MIN[rt << 1 | 1]);
    }
}

void update(int p, int val, int l, int r, int rt) {
    if (l == r) {
        MIN[rt] = val;
    } else {
        const int m = l + (r - l) / 2;
        if (p <= m) update(p, val, l, m, rt << 1);
        else update(p, val, m + 1, r, rt << 1 | 1);
        MIN[rt] = min(MIN[rt << 1], MIN[rt << 1 | 1]);
    }
}

int query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) return MIN[rt];
    const int m = l + (r - l) / 2;
    int ret = 10000;
    if (L <= m) ret = min(ret, query(L, R, l, m, rt << 1));
    if (R > m) ret = min(ret, query(L, R, m + 1, r, rt << 1 | 1));
    return ret;
}

int main() {
    int N, Q;
    scanf("%d", &N);
    build(1, N, 1);
    scanf("%d", &Q);
    int op, param1, param2;
    while (Q--) {
        scanf("%d %d %d", &op, &param1, &param2);
        if (op)
            update(param1, param2, 1, N, 1);
        else
            printf("%dn", query(param1, param2, 1, N, 1));
    }
    return 0;
}