#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int> > preCalc(1000001, vector<int>(21));

void preProc(int N) {
    for (int j = 1, k = 2; k <= N; ++j, k *= 2)
        for (int i = 0; i + k <= N; ++i)
            preCalc[i][j] = min(preCalc[i][j - 1], preCalc[i + k / 2][j - 1]);
}

int query(int Li, int Ri, int N) {
    int j = 0, k = 1, Len = Ri - Li + 1;
    while (k * 2 < Len) {
        ++j;
        k *= 2;
    }
    return min(preCalc[Li][j], preCalc[Ri - k + 1][j]);
}

int main() {
    int N, Q;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        scanf("%d", &preCalc[i][0]);
    preProc(N);
    scanf("%d", &Q);
    int Li, Ri;
    while (Q--) {
        scanf("%d %d", &Li, &Ri);
        printf("%dn", query(Li - 1, Ri - 1, N));
    }
    return 0;
}