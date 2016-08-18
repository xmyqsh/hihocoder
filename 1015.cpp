#include <iostream>
#include <cstring>

using namespace std;

char p[10001];
char s[1000001];
int Next[10001];

void genNext(int pLen) {
    int j = 0, k = -1;
    Next[j] = k;
    while (j < pLen) {
        if (k == -1 || p[j] == p[k]) {
            ++j; ++k;
            if (j < pLen && p[j] == p[k])
                Next[j] = Next[k];
            else
                Next[j] = k;
        } else {
            k = Next[k];
        }
    }
}

int kmp(int pLen, int sLen) {
    int i = 0, j = 0, cnt = 0;
    while (i < sLen) {
        if (j == -1 || s[i] == p[j]) {
            ++i; ++j;
            if (j == pLen) {
                ++cnt;
                j = Next[pLen];
            }
        } else {
            j = Next[j];
        }
    }
    return cnt;
}

int main() {
    int N;
    cin >> N;
    while (N--) {
        cin >> p >> s;
        int pLen = strlen(p);
        int sLen = strlen(s);
        genNext(pLen);
        cout << kmp(pLen, sLen) << endl;
    }
    return 0;
}