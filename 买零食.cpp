#include <iostream>
#include <vector>

using namespace std;
vector<float> A(51);
vector<int> B(51);

void dfs(int cur, int cnt, float sum, int eager, int N, int& ret) {
    if (cur > N || cnt > 3) return;
    if (cur == N && (int)(sum * 2) % 10 == 0) {
        ret = max(ret, eager);
        return;
    }
    dfs(cur + 1, cnt, sum, eager, N, ret);
    dfs(cur + 1, cnt + 1, sum + A[cur], eager + B[cur], N, ret);
}

int main() {
    int Q, N;
    cin >> Q;
    while (Q--) {
        cin >> N;
        for (int i = 0; i < N; ++i)
            cin >> A[i] >> B[i];
        int ret = 0;
        dfs(0, 0, 0, 0, N, ret);
        cout << ret << endl;
    }
    return 0;
}