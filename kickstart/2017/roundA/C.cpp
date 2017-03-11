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
using namespace std;

#define REPP(i,a,b) for(int i=(a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)
#define PER(i,a) for(int i = (a) - 1; i >= 0; --i)
#define SIZE(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int inf = 1e9;
int n, p[2005][4];
bool f[2005];

bool cover(int xl, int xh, int yl, int yh, int zl, int zh) {
    int len = xh - xl;
    REP(i, n) {
        int r = p[i][3];
        if (p[i][0] - r >= xl && p[i][0] + r <= xh &&
            p[i][1] - r >= yl && p[i][1] + r <= yh &&
            p[i][2] - r >= zl && p[i][2] + r <= zh) f[i] = true;
        else f[i] = false;
    }
    int minx = inf, maxx = -inf, miny = inf, maxy = -inf, minz = inf, maxz = -inf;
    REP(i, n) if (!f[i]) {
        int r = p[i][3];
        minx = min(p[i][0] - r, minx);
        maxx = max(p[i][0] + r, maxx);
        miny = min(p[i][1] - r, miny);
        maxy = max(p[i][1] + r, maxy);
        minz = min(p[i][2] - r, minz);
        maxz = max(p[i][2] + r, maxz);
    }
    return (maxx - minx <= len && maxy - miny <= len && maxz - minz <= len);
}

void solve() {
    cin >> n;
    REP(i, n) REP(j, 4) {
        cin >> p[i][j];
    }
    int minx = inf, maxx = -inf, miny = inf, maxy = -inf, minz = inf, maxz = -inf;
    REP(i, n) {
        int r = p[i][3];
        minx = min(p[i][0] - r, minx);
        maxx = max(p[i][0] + r, maxx);
        miny = min(p[i][1] - r, miny);
        maxy = max(p[i][1] + r, maxy);
        minz = min(p[i][2] - r, minz);
        maxz = max(p[i][2] + r, maxz);
    }

    int lo = 0, hi = inf;
    while (lo < hi) {
        int m = (lo + hi) / 2;
        if (cover(minx, minx + m, miny, miny + m, minz, minz + m) ||
            cover(maxx - m, maxx, miny, miny + m, minz, minz + m) ||
            cover(minx, minx + m, maxy - m, maxy, minz, minz + m) ||
            cover(maxx - m, maxx, maxy - m, maxy + m, minz, minz + m) ||
            cover(minx, minx + m, miny, miny + m, maxz - m, maxz) ||
            cover(maxx - m, maxx, miny, miny + m, maxz - m, maxz) ||
            cover(minx, minx + m, maxy - m, maxy, maxz - m, maxz) ||
            cover(maxx - m, maxx, maxy - m, maxy, maxz - m, maxz) ) hi = m;
        else lo = m + 1;
    }
    cout << lo << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int T; cin >> T;
    REP(i, T) {
        printf("Case #%d: ", i + 1);
        solve();
    }
    return 0;
}
