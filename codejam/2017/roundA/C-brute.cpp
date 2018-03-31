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

const int inf = 1e9;
int hd, ad, hk, ak, buff, debuff;

int calc(int b, int d) {
    int h1 = hd, a1 = ad, h2 = hk, a2 = ak;
    int res = b + d;
    bool prevCure = true, toCure;
    while (d--) {
        toCure = (h1 <= a2 - debuff);
        if (prevCure && toCure) return inf;
        if (toCure) h1 = hd, d++, res++;
        else a2 = max(a2 - debuff, 0);
        h1 -= a2;
        if (h1 <= 0) return inf;
        prevCure = toCure;
    }
    while (b--) {
        toCure = (h1 <= a2);
        if (prevCure && toCure) return inf;
        if (toCure) h1 = hd, b++, res++;
        else a1 += buff;
        h1 -= a2;
        if (h1 <= 0) return inf;
        prevCure = toCure;
    }
    while (true) {
        if (h2 <= a1) return ++res;
        toCure = (h1 <= a2);
        if (prevCure && toCure) return inf;
        res++;
        if (toCure) h1 = hd;
        else h2 -= a1;
        if (h2 <= 0) return res;
        h1 -= a2;
        if (h1 <= 0) return inf;
        prevCure = toCure;
    }
    return inf;
}

void solve() {
    cin >> hd >> ad >> hk >> ak >> buff >> debuff;
    int ans = inf;
    REP(i, 100) REP(j, 100) ans = min(ans, calc(i, j));
    if (ans == inf) cout << "IMPOSSIBLE" << endl;
    else cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int T; cin >> T;
    REP(i, T) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
    return 0;
}
