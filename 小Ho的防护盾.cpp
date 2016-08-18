#include <iostream>
#include <vector>

using namespace std;

const int maxN = 100000;

int N, M, K, maxA = 0;
vector<int> A(maxN + 1);

bool breaked(int T) {
    int k = 0;
    for (int i = 0, sum = 0; i < N && k < K; ++i) {
        sum += A[i];
        if (sum >= M) {
            ++k;
            sum = 0;
        }
        sum = max(0, sum - T);
    }
    return k == K;
}

int leastT(int b, int e) {
    while (b <= e) {
        const int mid = (b + e) / 2;
        if (breaked(mid))
            b = mid + 1;
        else
            e = mid - 1;
    }
    return b;
}

int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        if (A[i] > maxA)
            maxA = A[i];
    }
    cout << leastT(1, maxA) << endl;
    return 0;
}