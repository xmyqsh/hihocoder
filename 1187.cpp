#include <iostream>
#include <vector>

using namespace std;

vector<bool> isPrime(50, true);
vector<int> primes(50, 0);
int cnt = 0;
long long max_div, min_n;

void genPrime(void) {
    for (int i = 2; i < 50; ++i) {
        if (isPrime[i])
            primes[cnt++] = i;
        for (int j = i * i; j < 50; j += i)
            isPrime[j] = false;
    }
}

void dfs(long long div, int cur, long long n, long long left) {
    if (left < primes[cur]) {
        if (max_div < div || (max_div == div && n < min_n)) {
            max_div = div;
            min_n = n;
        }
        return;
    }
    for (int i = 2; primes[cur] <= left; ++i) {
        n *= primes[cur];
        left /= primes[cur];
        dfs(div * i, cur + 1, n, left);
    }
}

long long cal(long long n) {
    if (n == 1) return 1;
    dfs(1, 0, 1, n);
    return min_n;
}

int main() {
    genPrime();
    long long n;
    while (cin >> n) {
        max_div = 1;
        cout << cal(n) << endl;
    }
    return 0;
}