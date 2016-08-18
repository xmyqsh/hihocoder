#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_MN = 105;
int M, N;

vector<vector<int> > mat(MAX_MN, vector<int>(MAX_MN));
vector<vector<bool> > status(MAX_MN, vector<bool>(MAX_MN, false));
queue<pair<int, int> > q;

int calc(int x, int y) {
    int cnt = 0;
    if (x - 1 >= 0 && status[x - 1][y]) ++cnt;
    if (x + 1 < N && status[x + 1][y]) ++cnt;
    if (y - 1 >= 0 && status[x][y - 1]) ++cnt;
    if (y + 1 < M && status[x][y + 1]) ++cnt;
    return cnt;
}

int main() {
    int x, y, val;
    cin >> N >> M >> x >> y;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> mat[i][j];
    status[x][y] = true;
    val = mat[x][y];
    int total = 4;
    q.push(make_pair(x, y));
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        x = cur.first;
        y = cur.second;
        if (x - 1 >= 0 && mat[x - 1][y] == val && !status[x - 1][y]) {
            if (calc(x - 1, y) == 1) {
                total += 2;
            }
            q.push(make_pair(x - 1, y));
            status[x - 1][y] = true;
        }
        if (x + 1 < N && mat[x + 1][y] == val && !status[x + 1][y]) {
            if (calc(x + 1, y) == 1) {
                total += 2;
            }
            q.push(make_pair(x + 1, y));
            status[x + 1][y] = true;
        }
        if (y - 1 >= 0 && mat[x][y - 1] == val && !status[x][y - 1]) {
            if (calc(x, y - 1) == 1) {
                total += 2;
            }
            q.push(make_pair(x, y - 1));
            status[x][y - 1] = true;
        }
        if (y + 1 < M && mat[x][y + 1] == val && !status[x][y + 1]) {
            if (calc(x, y + 1) == 1) {
                total += 2;
            }
            q.push(make_pair(x, y + 1));
            status[x][y + 1] = true;
        }
    }
    cout << total << endl;
    return 0;
}