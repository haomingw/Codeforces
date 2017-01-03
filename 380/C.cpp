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
#define X first
#define Y second

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 2e5 + 5;
int n, k, s, t, p, v, g[maxn];
set<pii> car;

bool check(int vol) {
    int time = 0;
    REP(i, k + 1) {
        int d = g[i + 1] - g[i];
        if (d > vol) return false;
        if (2 * d <= vol) time += d;
        else time += 3 * d - vol;
    }
    return time <= t;
}

int main() {
    scanf("%d%d%d%d", &n, &k, &s, &t);
    REP(i, n) {
        scanf("%d%d", &p, &v);
        car.insert(MP(p, v));
    }
    g[0] = 0; g[k + 1] = s;
    REP(i, k) scanf("%d", g + i + 1);
    sort(g, g + k + 1);
    ll l = 0, r = 2e9;
    while (l < r) {
        // clog << l << " " << r << endl;
        ll m = (l + r) / 2;
        if (check(m)) r = m;
        else l = m + 1;
    }
    for (pii c : car) {
        int prix = c.first, vol = c.second;
        if (vol >= l) return !printf("%d\n", prix);
    }
    cout << -1 << endl;
    return 0;
}
