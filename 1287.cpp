#include <iostream>
#include <vector>

using namespace std;
#define LL long long

int a[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
int aSize = 12;

LL mod_mul(LL a, LL b, LL n) {
    LL ret = 0;
    while (b) {
        if (b & 1) ret = (ret + a) % n;
        b >>= 1;
        a = (a + a) % n;
    }
    return ret;
}

LL mod_exp(LL a, LL b, LL n) {
    LL ret = 1;
    while (b) {
        if (b & 1) ret = mod_mul(ret, a, n);
        b >>= 1;
        a = mod_mul(a, a, n);
    }
    return ret;
}

bool MR(LL n) {
    if (n <= 2) {
        if (n == 2) return true;
        return false;
    }
    if (!(n % 2)) return false;
    LL u = n - 1;
    while (!(u % 2)) u /= 2;
    for (int i = 0; i < aSize; ++i) {
        if (a[i] >= n) continue;
        LL x = mod_exp(a[i], u, n);
        while (u < n) {
            LL y = mod_exp(x, 2, n);
            if (y == 1 && x != 1 && x != n - 1) return false;
            x = y;
            u *= 2;
        }
        if (x != 1) return false;
    }
    return true;
}

int main() {
    LL t, num;
    cin >> t;
    while (t--) {
        cin >> num;
        cout << (MR(num) ? "Yes" : "No") << endl;
    }
    return 0;
}