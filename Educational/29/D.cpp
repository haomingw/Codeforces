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

const int maxn = 2e5 + 5;
int a[maxn];

struct query {
    int t, l, r;
    query(int t, int l, int r): t(t), l(l), r(r) {}
};

int solve(int x, query& q) {
    int t = q.t, l = q.l, r = q.r;
    assert(x >= l && x <= r);
    if (t == 1)
        return l + (x - 2 * l + r) % (r - l + 1);
    return r - x + l;
}

int main() {
    int n, q, m;
    scanf("%d%d%d", &n, &q, &m);
    REP(i, n) scanf("%d", a + i + 1);
    int t, l, r, x;
    vector<query> v;
    REP(i, q) {
        scanf("%d%d%d", &t, &l, &r);
        v.push_back(query(t, l, r));
    }
    map<int, int> mp;
    while (m--) {
        scanf("%d", &x);
        if (mp.count(x)) {
            printf("%d ", a[mp[x]]);
            continue;
        }
        int prev = x;
        PER(i, q) {
            query qq = v[i];
            if (x < qq.l || x > qq.r) continue;
            x = solve(x, qq);
        }
        mp[prev] = x;
        printf("%d ", a[x]);
    }
    return 0;
}
