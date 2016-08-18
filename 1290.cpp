#include <iostream>
#include <vector>

using namespace std;
vector<vector<int> > grid(105, vector<int>(105));
vector<vector<vector<int> > > dp(105, vector<vector<int> >(105, vector<int>(2, 20001)));
int N, M;

int calc() {
    if (N == 1 && M == 1) return grid[0][0] ? 0 : 1;
    if (N == 1) {
        int ret = 0;
        for (int j = 0; j < M; ++j) if (!grid[0][j]) ++ret;
        return ret;
    }
    if (M == 1) {
        int ret = 0;
        for (int i = 0; i < N; ++i) if (!grid[i][0]) ++ret;
        return ret;
    }
    dp[0][0][0] = grid[0][0] ? 0 : 1;
    dp[1][0][1] = dp[0][0][0] + (grid[0][1] ? 1 : 0) + (grid[1][0] ? 0 : 1);
    for (int i = 2; i < N; ++i)
        dp[i][0][1] = dp[i - 1][0][1] + (grid[i][0] ? 0 : 1);
    for (int j = 1; j < M; ++j)
        dp[0][j][0] = dp[0][j - 1][0] + (grid[0][j] ? 0 : 1);
    for (int i = 1; i < N - 1; ++i) {
        for (int j = 1; j < M - 1; ++j) {
            dp[i][j][0] = min(dp[i][j - 1][0], dp[i][j - 1][1] + (grid[i + 1][j - 1] ? 1 : 0)) + (grid[i][j] ? 0 : 1);
            dp[i][j][1] = min(dp[i - 1][j][0] + (grid[i - 1][j + 1] ? 1 : 0), dp[i - 1][j][1]) + (grid[i][j] ? 0 : 1);
        }
    }
    for (int i = 1; i < N - 1; ++i) {
        dp[i][M - 1][0] = min(dp[i][M - 2][0], dp[i][M - 2][1] + (grid[i + 1][M - 2] ? 1 : 0)) + (grid[i][M - 1] ? 0 : 1);
        dp[i][M - 1][1] = min(dp[i - 1][M - 1][0], dp[i - 1][M - 1][1]) + (grid[i][M - 1] ? 0 : 1);
    }
    for (int j = 1; j < M - 1; ++j) {
        dp[N - 1][j][0] = min(dp[N - 1][j - 1][0], dp[N - 1][j - 1][1]) + (grid[N - 1][j] ? 0 : 1);
        dp[N - 1][j][1] = min(dp[N - 2][j][0] + (grid[N - 2][j + 1] ? 1 : 0), dp[N - 2][j][1]) + (grid[N - 1][j] ? 0 : 1);
    }
    dp[N - 1][M - 1][0] = min(dp[N - 1][M - 2][0], dp[N - 1][M - 2][1]) + (grid[N - 1][M - 1] ? 0 : 1);
    dp[N - 1][M - 1][1] = min(dp[N - 2][M - 1][0], dp[N - 2][M - 1][1]) + (grid[N - 1][M - 1] ? 0 : 1);
    return min(dp[N - 1][M - 1][0], dp[N - 1][M - 1][1]);
}

int main() {
    char ch;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> ch;
            if (ch == '.') grid[i][j] = 1;
            else grid[i][j] = 0;
        }
    }
    cout << calc() << endl;
    return 0;
}