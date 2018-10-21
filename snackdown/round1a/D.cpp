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

const int maxn = 30;
map<int, int> memo[maxn][maxn];

int nbits(int a) {
    int cnt = 0;
    REP(i, 30) if (a & (1 << i)) cnt++;
    return cnt;
}

int calc(int na, int nb, int c) {
    if (max(na, nb) > 0 && c == 0) return 0;
    if (na == 0) {
        if (nbits(c) == nb) return 1;
        else return 0;
    } else if (nb == 0) {
        if (nbits(c) == na) return 1;
        else return 0;
    }
    if (memo[na][nb].count(c)) return memo[na][nb][c];
    int res;
    if (c & 1) {
        res = calc(na - 1, nb, c / 2) + calc(na, nb - 1, c / 2);
    } else {
        res = calc(na, nb, c / 2) + calc(na - 1, nb - 1, c / 2 - 1);
    }
    memo[na][nb][c] = res;
    return res;
}

void solve() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    REP(i, maxn) REP(j, maxn) if (!memo[i][j].empty()) memo[i][j].clear();
    int na = nbits(a), nb = nbits(b);
    int ans = calc(na, nb, c);
    printf("%d\n", ans);
}

int main() {
    int T; cin >> T;
    REP(i, T) {
        solve();
    }
    return 0;
}
