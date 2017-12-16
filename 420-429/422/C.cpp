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

const int inf = 2e9 + 5;
const int maxn = 2e5 + 5;

vector<pii> a[maxn], b[maxn];
int c[maxn];

int main() {
    int n, x;
    scanf("%d%d", &n, &x);
    int l, r, cost;
    REP(i, n) {
        scanf("%d%d%d", &l, &r, &cost);
        a[l].push_back(MP(r - l + 1, cost));
        b[r].push_back(MP(r - l + 1, cost));
    }
    REP(i, maxn) c[i] = inf;
    int ans = inf;
    REP(i, maxn) {
        for (pii p : a[i]) {
            if (p.first >= x) continue;
            if (c[x - p.first] < inf) ans = min(ans, c[x - p.first] + p.second);
        }
        for (pii p : b[i])
            c[p.first] = min(c[p.first], p.second);
    }
    cout << (ans == inf ? -1 : ans) << endl;
    return 0;
}
