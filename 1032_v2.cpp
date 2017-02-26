#include <iostream>
#include <string>
#include <vector>

using namespace std;

int calc(const string& s) {
    if (s.size() < 2) return s.size();

    string ss(2 * s.size() + 3, '$');
    ss[0] = '#'; ss[ss.size() - 1] = '@';
    for (int i = 0; i < s.size(); ++i)
        ss[2 * (i + 1)] = s[i];

    vector<unsigned int> f(ss.size(), 0);
    unsigned int mask = ~(1);
    int ret = 1, t = 0, max_t_ft = -1; // max = t + f[t]
    for (int i = 1; i < ss.size() - 1; ++i) {
        if (max_t_ft >= i) f[i] = min((int)f[2 * t - i], max_t_ft - i);
        while (ss[i - f[i] - 1] == ss[i + f[i] + 1]) ++f[i];
        if (i % 2) ret = max(ret, (int)f[i]);
        else ret = max(ret, 1 + int(f[i] & mask));
        if (max_t_ft < i + f[i]) {
            t = i;
            max_t_ft = i + f[i];
        }
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
