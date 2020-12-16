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

void solve() {
    int n, r;
    cin >> n >> r;
    int x[50], y[50], ans = 0;
    REP(i, n) cin >> x[i] >> y[i];
    REP(a, n) REPP(b, a, n) REP(c, n) REPP(d, c, n) {
        int add = 0;
        int x1 = min(x[a], x[b]), y1 = min(y[a], y[b]),
            x2 = min(x[c], x[d]), y2 = min(y[c], y[d]);
        REP(i, n) {
            add += (x[i] >= x1 && x[i] <= x1 + r && y[i] >= y1 && y[i] <= y1 + r) ||
                   (x[i] >= x2 && x[i] <= x2 + r && y[i] >= y2 && y[i] <= y2 + r);
        }
        ans = max(ans, add);
    }
    cout << ans << endl;
}

int main() {
    clock_t start = clock();
    int T; cin >> T;
    REP(i, T) {
        printf("Case #%d: ", i + 1);
        solve();
    }
    clock_t end = clock();
    double time = (double) (end - start) / CLOCKS_PER_SEC * 1000.0;
    clog << "time: " << time  << "ms" << endl;
    return 0;
}
