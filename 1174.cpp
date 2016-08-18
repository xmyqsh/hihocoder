#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<int, vector<int> > graph;
vector<int> counts(100000);

void dfs(int& cnt, int i) {
    --cnt;
    counts[i] = -1;
    for (int j = 0; j < graph[i].size(); ++j)
        if (--counts[graph[i][j]] == 0)
            dfs(cnt, graph[i][j]);
}

int main() {
    int T;
    cin >> T;
    int M, N;
    while (T--) {
        graph.clear();
        fill_n(counts.begin(), counts.size(), 0);
        cin >> M >> N;
        int a, b;
        for (int i = 0; i < N; ++i) {
            cin >> a >> b;
            graph[a - 1].push_back(b - 1);
            counts[b - 1]++;
        }
        int cnt = M;
        for (int i = 0; i < M; ++i)
            if (counts[i] == 0)
                dfs(cnt, i);
        cout << (cnt == 0 ? "Correct" : "Wrong") << endl;
    }
    return 0;
}