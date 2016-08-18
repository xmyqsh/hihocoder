#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MOD = 1000000007;
int N, M, len;
vector<vector<vector<int> > > cache;

bool getBit(int s, int pos) {
    return (s & (1 << pos));
}

int setBit(int s, int pos1, int pos2) {
    return (s | (1 << pos1) | (1 << pos2));
}

int calc(int i, int j, int s) {
    if (i >= N || j >= M || s >= len)
        return 1;
    if (cache[i][j][s] != -1)
        return cache[i][j][s];
    int result = 0;
    if (getBit(s, j)) {
        if (j < M - 1)
            result = calc(i, j + 1, s);
        else
            result = calc(i + 1, 0, (s >> M));
    } else {
        if (j == M - 1 || getBit(s, j + 1)) {
            if (i == N - 1 || getBit(s, j + M)) {
                result = 0;
            } else {
                result = calc(i, j, setBit(s, j, j + M));
            }
        } else {
            if (i == N - 1 || getBit(s, j + M)) {
                result = calc(i, j, setBit(s, j, j + 1));
            } else {
                result = (calc(i, j, setBit(s, j, j + M)) + calc(i, j, setBit(s, j, j + 1))) % MOD;
            }
        }
    }

    cache[i][j][s] = result;
    //cout << "i: " << i << ", j: " << j << ", s: " << s << ", cache[i][j][s]: " << result << endl;

    return result;
}

int main() {
    cin >> N >> M;
    len = pow(2, 2 * M);
    cache = vector<vector<vector<int> > >(N, vector<vector<int> >(M, vector<int>(len, -1)));
    if ((N * M) % 2)
        cout << 0 << endl;
    else
        cout << calc(0, 0, 0) << endl;
    return 0;
}