#include <iostream>

using namespace std;

int calc(int n, int k) {
    int ret = 0;
    for (int i = 2; i <= n; ++i) ret = (ret + k) % i;
    return ret;
}

int calc1(int n, int k) {
    if (n == 1) return 0;
    if (n < k) return calc(n, k);
    int ret = calc1(n - n / k, k), m = n % k;
    if (ret < m) ret = ret - m + n;
    else ret = ret - m + (ret - m) / (k - 1);
    return ret;
}

int main() {
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cout << calc1(n, k) << endl;
    }
    return 0;
}