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

const int inf = 1e9;
const int maxn = 2e5 + 5;
int l[maxn], r[maxn];
int rmq[maxn * 8], dd[maxn * 8];

void add(int v, int tl, int tr, int left, int right) {
    if (tr <= left || tl >= right) return;
    if (tl >= left && tr <= right) {
        rmq[v]++;
        dd[v]++;
        return;
    }
    int m = (tl + tr) >> 1;
    add(2 * v + 1, tl, m, left, right);
    add(2 * v + 2, m, tr, left, right);
    rmq[v] = min(rmq[2 * v + 1], rmq[2 * v + 2]) + dd[v];
}

int get(int v, int tl, int tr, int left, int right) {
    if (tr <=left || right <= tl) return inf;
    if (tl >= left && tr <= right) return rmq[v];
    int m = (tl + tr) >> 1;
    int lson = get(2 * v + 1, tl, m, left, right),
        rson = get(2 * v + 2, m, tr, left, right);
    return min(lson, rson) + dd[v];
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> v;
    REP(i, n) {
        scanf("%d%d", l + i, r + i);
        r[i]++;
        v.push_back(l[i]);
        v.push_back(r[i]);
    }
    sort(ALL(v));
    v.resize(unique(ALL(v)) - v.begin());
    int x = v.size();
    REP(i, n) {
        l[i] = lower_bound(ALL(v), l[i]) - v.begin();
        r[i] = lower_bound(ALL(v), r[i]) - v.begin();
        add(0, 0, x, l[i], r[i]);
    }
    REP(i, n) {
        int q = get(0, 0, x, l[i], r[i]);
        if (q >= 2) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
