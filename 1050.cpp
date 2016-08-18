#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
#define N 1005
int dp[N], a[N];

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        for(int i = 0; i < n; ++i)
            cin >> a[i];
		for(int i = 0; i < m; ++i)
			dp[i] = INT_MAX;
		dp[m] = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j <= m; ++j){
				int tmp = INT_MAX;
                int bound = a[i] % s ? a[i] / s + 1 : a[i] / s;
                for(int x = 0, rest = a[i]; x <= bound; ++x, rest -= s){
					int error = 0;
					if(rest > 0)
						error = rest % t ? rest / t + 1 : rest / t;
                    int k = j + x + error;
                    if(k > m || dp[k] == INT_MAX)
                        continue;
                    tmp = min(dp[k] + x, tmp);
                }
				dp[j] = tmp;
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i <= m; ++i)
			ans = min(ans, dp[i]);
		if(ans == INT_MAX)
			cout << "No" << endl;
		else
			cout << ans << endl;
    }
    return 0;
}