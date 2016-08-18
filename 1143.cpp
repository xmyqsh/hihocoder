#include <iostream>

using namespace std;

const int MOD = 19999997;

int calc(int n) {
    int prev = 1, cur = 1;
    while (--n) {
        int tmp = cur;
        cur = (cur + prev) % MOD;
        prev = tmp;
    }
    return cur;
}

int main() {
    int N;
    cin >> N;
    cout << calc(N) << endl;
    return 0;
}