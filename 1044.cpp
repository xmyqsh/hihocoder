#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int ones(int n) {
    int cnt = 0;
    while (n) {
        n &= n - 1;
        ++cnt;
    }
    return cnt;
}

int calc(const vector<int>& garbage, int M, int Q) {
    vector<int> dp(pow(2, M - 1));
    for (int i = 0; i < garbage.size(); ++i) {
        vector<int> nextDp(pow(2, M - 1));
        for (int j = 0; j < pow(2, M - 1); ++j) {
            if (ones(j) < Q)
                nextDp[j / 2 + pow(2, M - 2)] = max(nextDp[j / 2 + pow(2, M - 2)], dp[j] + garbage[i]);
            nextDp[j / 2] = max(nextDp[j / 2], dp[j]);
        }
        swap(dp, nextDp);
    }
    int ret = 0;
    for (int j = 0; j < pow(2, M - 1); ++j)
        ret = max(ret, dp[j]);
    return ret;
}

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<int> garbage(N);
    for (int i = 0; i < N; ++i)
        cin >> garbage[i];
    cout << calc(garbage, M, Q) << endl;
    return 0;
}