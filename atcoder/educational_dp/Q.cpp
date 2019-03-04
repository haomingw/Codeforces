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
#define REPP(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)
#define PER(i,a) for(int i = (a) - 1; i >= 0; --i)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 2e5 + 5;
int n, a[maxn], h[maxn];
ll tree[maxn];

ll query(int x) {
    ll res = 0;
    while (x) {
        res = max(res, tree[x]);
        x -= x & (-x);
    }
    return res;
}

void update(int x, ll val) {
    while (x <= n) {
        tree[x] = max(tree[x], val);
        x += x & (-x);
    }
}

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", h + i);
    REP(i, n) scanf("%d", a + i);
    ll ans = 0;
    REP(i, n) {
        ll x = query(h[i]);
        update(h[i], x + a[i]);
        ans = max(ans, x + a[i]);
    }
    cout << ans << endl;
    return 0;
}
