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
#define SIZE(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 55;
int n, p, pos[maxn], r[maxn], q[maxn][maxn];

pii range(int a, int b) {
    int low = (a * 10 + b * 11 - 1) / (b * 11),
        high = a * 10 / (b * 9);
    return MP(low, high);
}

int solve() {
    cin >> n >> p;
    REP(i, n) cin >> r[i];
    REP(i, n) REP(j, p) cin >> q[i][j];
    REP(i, n) {
        memset(pos, 0, sizeof(pos));
        sort(q[i], q[i] + p);
    }
    int ans = 0;
    while (true) {
        int l = -1e9, h = 1e9, ind = 0;
        REP(i, n) {
            if (pos[i] >= p) return ans;
            pii t = range(q[i][pos[i]], r[i]);
            l = max(l, t.first);
            if (t.second < h) ind = i;
            h = min(h, t.second);
        }
        if (l <= h) {
            ans++;
            REP(i, n) pos[i]++;
        } else pos[ind]++;
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int T; cin >> T;
    REP(i, T) {
        printf("Case #%d: ", i + 1);
        cout << solve() << endl;
    }
    return 0;
}
