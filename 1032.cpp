#include <iostream>
#include <string>
#include <vector>

using namespace std;

int calc(const string& s) {
    if (s.size() < 2)
        return s.size();
    string ss(2 * s.size(), '#');
    for (int i = 0; i < s.size(); ++i) {
        ss[2 * i] = s[i];
    }
    ss.erase(2 * s.size() - 1, 1);

    vector<int> f(ss.size(), 1);
    int ret = 1, j = 0, f_j = 0, left, right, real;
    if (ss[0] == ss[2]) {
        j = 1;
        f_j = 2;
    }
    for (int i = 2; i < ss.size(); ++i) {
        f[i] = max(1, min(f[2 * j - i], f[j] - 2 * (i - j)));
        left = i - f[i] / 2 - 1;
        right = i + f[i] / 2 + 1;
        while (left >= 0 && right < ss.size() && ss[left] == ss[right]) {
            --left;
            ++right;
        }
        f[i] = right - left - 1;
        if (right - 1 > f_j) {
            j = i;
            f_j = right - 1;
        }
        if (i % 2) {
            real = (f[i] + 1) / 4 * 2;
        } else {
            real = ((f[i] + 3) / 4 - 1) * 2 + 1;
        }
        ret = max(ret, real);
    }
    return ret;
}

int main() {
    int T;
    cin >> T;
    string s;
    while (T--) {
        cin >> s;
        cout << calc(s) << endl;
    }
    return 0;
}