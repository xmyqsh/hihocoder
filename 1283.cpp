#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> array(N);
    for (int i = 0; i < N; ++i)
        cin >> array[i];
    int end = N - 2;
    while (end >= 0 && array[end] < array[end + 1]) --end;
    end = max(0, end);
    for (int i = 0; i < end; ++i)
        cout << array[i] << " ";
    cout << array[end] << endl;
    return 0;
}