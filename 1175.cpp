#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int MOD = 142857;
map<int, vector<int> > graph;
vector<int> counts(100000, 0);
vector<int> A(100000, 0);

void dfs(int& cnt, int i, int& ret) {
    --cnt;
    counts[i] = -1;
    ret += A[i];
    ret %= MOD;
    for (int j = 0; j < graph[i].size(); ++j) {
        A[graph[i][j]] += A[i];
        A[graph[i][j]] %= MOD;
        if (--counts[graph[i][j]] == 0)
            dfs(cnt, graph[i][j], ret);
    }
}

int main() {
    int M, N, K, c;
    cin >> N >> M >> K;
    for (int i = 0; i < K; ++i) {
        cin >> c;
        A[c - 1] = 1;
    }
    int a, b;
    for (int i = 0; i < M; ++i) {
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        counts[b - 1]++;
    }
    int cnt = N, ret = 0;
    for (int i = 0; i < N; ++i)
        if (counts[i] == 0)
            dfs(cnt, i, ret);
    cout << ret << endl;
    return 0;
}