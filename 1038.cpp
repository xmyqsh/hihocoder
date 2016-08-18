#include <iostream>
#include <vector>

using namespace std;

int calc(const vector<int>& need, const vector<int>& value, int M) {
    vector<int> dp(M, 0);
    for (int i = 0; i < need.size(); ++i)
        for (int j = M - 1; j >= need[i]; --j)
            dp[j] = max(dp[j], dp[j - need[i]] + value[i]);
    return dp[M - 1];
}

int main() {
    int n, M;
    cin >> n >> M;
    vector<int> need(n), value(n);
    for (int i = 0; i < n; ++i)
        cin >> need[i] >> value[i];
    cout << calc(need, value, M) << endl;
    return 0;
}