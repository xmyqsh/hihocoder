#include <iostream>
#include <vector>

using namespace std;

vector<int> a(1005);
int TASKS, N, P, W, H;

bool can(int S) {
    int nLine = 0, perLine = W / S;
    for (int i = 0; i < N; ++i)
        nLine += (a[i] % perLine) == 0 ? a[i] / perLine : a[i] / perLine + 1;
    return P * (H / S) >= nLine;
}

int calc() {
    int b = 1, e = W;
    while (b <= e) {
        const int m = b + (e - b) / 2;
        if (can(m)) b = m + 1;
        else e = m - 1;
    }
    return e;
}

int main() {
    cin >> TASKS;
    while (TASKS--) {
        cin >> N >> P >> W >> H;
        for (int i = 0; i < N; ++i)
            cin >> a[i];
        cout << calc() << endl;
    }
}