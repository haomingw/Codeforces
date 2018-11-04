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

int n, m, a, b;

int calc(int r, int c) {
    int res = 1;
    res += n + m - 2;
    res += min(r, c) + min(n - 1 - r, m - 1 - c);
    res += min(r, m - 1 - c) + min(n - 1 - r, c);
    bool used = false;
    if (r == a) res -= c < b ? m - 1 - b : b, used = true;
    if (c == b) res -= r < a ? n - 1 - a : a, used = true;
    if (r - c == a - b) {
        res -= r < a ? min(n - 1 - a, m - 1 - b) : min(a, b);
        used = true;
    }
    if (r + c == a + b) {
        res -= r < a ? min(n - 1 - a, b) : min(a, m - 1 - b);
        used = true;
    }
    if (!used) res++;
    return res;
}

void solve() {
    scanf("%d%d%d%d", &n, &m, &a, &b);
    a--, b--;
    int ans = 0;
    REP(i, n) REP(j, m) {
        if (i == a && j == b) continue;
        ans += n * m - calc(i, j);
    }
    printf("%d\n", ans);
}

int main() {
    int T; cin >> T;
    REP(i, T) {
        solve();
    }
    return 0;
}
