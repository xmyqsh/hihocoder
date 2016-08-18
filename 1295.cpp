#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

const int MAX_N = 1000001;

vector<int> primeList(MAX_N);
vector<int> isPrime(MAX_N, 1);
vector<int> cntPrime(MAX_N, 0);
int primeCnt = 0;

void genPrime() {
    for (int i = 2; i < MAX_N; ++i) {
        if (isPrime[i]) {
            primeList[primeCnt++] = i;
            cntPrime[i] = cntPrime[i - 1] + 1;
        } else {
            cntPrime[i] = cntPrime[i - 1];
        }
        for (int j = 0, k = primeList[j] * i; j < primeCnt && k < MAX_N; ++j, k = primeList[j] * i) {
            isPrime[k] = 0;
            if (i % primeList[j] == 0) break;
        }
    }
}

int main() {
    genPrime();
    int n;
    cin >> n;
    cout << cntPrime[n] << endl;
    return 0;
}