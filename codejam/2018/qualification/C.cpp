#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <utility>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cassert>
using namespace std;

#define REPP(i,a,b) for(int i=(a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)
#define PER(i,a) for(int i = (a) - 1; i >= 0; --i)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 1005;
bool used[maxn][maxn];
int a, b;

void print(int i, int j) {
    cout << i << " " << j << endl;
    fflush(stdout);
}

int calc(int x, int y) {
    int sum = 0;
    REPP(i, x - 1, x + 2) REPP(j, y - 1, y + 2) sum += int(!used[i][j]);
    return sum;
}

void update(int len) {
    int best = 0;
    for (int j = 2; j < len; j++) {
        int sum = calc(2, j);
        if (sum > best) best = sum, b = j;
    }
}

void init() {
    a = b = 2;
    REP(i, maxn) REP(j, maxn) used[i][j] = false;
}

void solve(int t) {
    init();
    int n; cin >> n;
    int i, j, len = max((n + 2) / 3, 3);
    int cnt = 0;
    while (true) {
        cnt++;
        print(a, b);
        cin >> i >> j;
        if (i == 0 || j == 0) break;
        assert(i > 0 && j > 0);
        used[i][j] = true;
        update(len);
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int T; cin >> T;
    REP(i, T) {
        solve(i + 1);
    }
    return 0;
}
