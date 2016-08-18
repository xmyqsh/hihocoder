#include <iostream>
#include <vector>

using namespace std;

int main() {
    int P, Q;
    cin >> P >> Q;
    vector<int> q;
    for (int i = 1; i <= Q; ++i)
        if (!(Q % i))
            q.push_back(i);
    for (int i = 1; i <= P; ++i) {
        if (!(P % i)) {
            for (int j = 0; j != q.size(); ++j)
                cout << i << " " << q[j] << endl;
        }
    }
    return 0;
}