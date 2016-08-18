#include <iostream>
#include <vector>

using namespace std;

vector<int> degree(10000, 0);

int main() {
    int N, M;
    cin >> N >> M;
    int a, b;
    for (int i = 0; i < M; ++i) {
        cin >> a >> b;
        degree[a - 1]++;
        degree[b - 1]++;
    }
    int odd = 0;
    for (int i = 0; i < N; ++i)
        if (degree[i] % 2)
            ++odd;
    cout << ((odd == 0 || odd == 2) ? "Full" : "Part") << endl;
    return 0;
}