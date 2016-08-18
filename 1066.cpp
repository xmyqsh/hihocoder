#include <iostream>
#include <map>

using namespace std;

map<string, int> mp;
map<int, int> fa;
int m = 0;

int read() {
    string str;
    cin >> str;
    if (mp.count(str)) return mp[str];
    mp[str] = ++m;
    fa[m] = m;
    return m;
}

int find(int x) {
    int y = x;
    for (; x != fa[x]; x = fa[x]);
    return fa[y] = x;
}

int main() {
    int N;
    cin >> N;
    int op;
    while (N--) {
        cin >> op;
        int x = find(read());
        int y = find(read());
        if (op & 1)
            cout << (x == y ? "yes" : "no") << endl;
        else
            fa[max(x, y)] = min(x, y);
    }
}