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

const ll inf = 1e18;
const int maxn = 5005;
int nxt[maxn];
int p[maxn], a[maxn], b[maxn], c[maxn], d[maxn];

ll go(int i, int j) {
    if (j < i) return (ll)p[i] - p[j] + c[i] + b[j];
    else return ll(p[j]) - p[i] + d[i] + a[j];
}

int main() {
    int n, s, e;
    scanf("%d%d%d", &n, &s, &e);
    s--, e--;
    REP(i, n) scanf("%d", &p[i]);
    REP(i, n) scanf("%d", &a[i]);
    REP(i, n) scanf("%d", &b[i]);
    REP(i, n) scanf("%d", &c[i]);
    REP(i, n) scanf("%d", &d[i]);
    ll ans = go(s, e);
    nxt[s] = e;
    REP(i, n) {
        if (i == s || i == e) continue;
        ll best = inf;
        int pre;
        for (int x = s; x != e; x = nxt[x]) {
            ll tmp = go(x, i) + go(i, nxt[x]) - go(x, nxt[x]);
            if (tmp < best) {
                best = tmp;
                pre = x;
            }
        }
        nxt[i] = nxt[pre];
        nxt[pre] = i;
        ans += best;
    }
    cout << ans << endl;
    return 0;
}
