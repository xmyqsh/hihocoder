#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>

using namespace std;
const int MAXN = 100005;
const int MAXL = 1000000005;
vector<int> rLeft(MAXN);
vector<int> rRight(MAXN);
vector<int> top(MAXN << 2);
set<int> st;
map<int, int> mp;

void lazyDown(int rt, int l, int r) {
    if (top[rt] && l < r) {
        top[rt << 1] = top[rt << 1 | 1] = top[rt];
        top[rt] = 0;
    }
}

void update(int L, int R, int val, int l, int r, int rt) {
    if (L <= l && r <= R) {
        top[rt] = val;
    } else {
        lazyDown(rt, l, r);
        const int m = l + (r - l) / 2;
        if (L < m) update(L, R, val, l, m, rt << 1);
        if (R > m) update(L, R, val, m, r, rt << 1 | 1);
    }
}

int query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) return top[rt];
    lazyDown(rt, l, r);
    const int m = l + (r - l) / 2;
    if (L < m) return query(L, R, l, m, rt << 1);
    else /* R > m */ return query(L, R, m, r, rt << 1 | 1);
}

int main() {
    fill(top.begin(), top.end(), 0);
    int N, L, a_i, b_i;
    scanf("%d %d", &N, &L);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &rLeft[i]);
        scanf("%d", &rRight[i]);
        st.insert(rLeft[i]);
        st.insert(rRight[i]);
    }
    int i = 1;
    for (set<int>::iterator iter = st.begin(); iter != st.end(); ++iter)
        mp[*iter] = i++;
    for (int i = 1; i <= N; ++i)
        update(mp[rLeft[i - 1]], mp[rRight[i - 1]], i, 1, st.size(), 1);
    set<int> tops;
    for (int i = 1; i < st.size(); ++i) {
        int id = query(i, i + 1, 1, st.size(), 1);
        if (id) tops.insert(id);
    }
    cout << tops.size() << endl;
    return 0;
}