#include <iostream>
#include <vector>

using namespace std;

int calc(const vector<vector<int> >& triangle) {
    if (triangle.empty()) return 0;
    vector<vector<int> > dp(triangle.size(), vector<int>(triangle.size(), 0));
    dp[0][0] = triangle[0][0];
    int ret = dp[0][0];
    for (int i = 1; i < triangle.size(); ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0)
                dp[i][j] = dp[i - 1][j] + triangle[i][j];
            else if (j == i)
                dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
            else
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            if (i == triangle.size() - 1)
                ret = max(ret, dp[i][j]);
        }
    }
    return ret;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int> > triangle(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= i; ++j)
            cin >> triangle[i][j];
    cout << calc(triangle) << endl;
    return 0;
}