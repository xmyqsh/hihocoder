#include <iostream>
#include <vector>

using namespace std;

int calc(const vector<int>& need, const vector<int>& value, int M) {
    vector<int> dp(M, 0);
    for (int i = 0; i < need.size(); ++i)
        for (int j = need[i]; j < M; ++j)
            dp[j] = max(dp[j], dp[j - need[i]] + value[i]);
    return dp[M - 1];
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> need(N), value(N);
    for (int i = 0; i < N; ++i)
        cin >> need[i] >> value[i];
    cout << calc(need, value, M) << endl;
    return 0;
}