#include <iostream>
#include <vector>

using namespace std;

int travel(const vector<vector<int> >& graph, vector<int>& visited, int& ret, int i) {
    visited[i] = 1;
    int first = 0, second = 0;
    for (int j = 0; j < graph[i].size(); ++j) {
        if (visited[graph[i][j]]) continue;
        int subRet = travel(graph, visited, ret, graph[i][j]);
        if (subRet > first) {
            second = first;
            first = subRet;
        } else if (subRet > second) {
            second = subRet;
        }
    }
    if (first + second > ret)
        ret = first + second;
    return first + 1;
}

int main() {
    int N, a, b, ret = 0;
    cin >> N;
    vector<vector<int> > graph(N + 1, vector<int>());
    vector<int> visited(N + 1, 0);
    for (int i = 1; i < N; ++i) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    travel(graph, visited, ret, 1);
    cout << ret << endl;
    return 0;
}