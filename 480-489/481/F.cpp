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
int n, k, a[maxn];
vector<pii> v;
vector<int> g[maxn];

int main() {
    scanf("%d%d", &n, &k);
    int x, y;
    REP(i, n) {
        scanf("%d", &x);
        v.push_back(MP(x, i));
        a[i] = x;
    }
    REP(i, k) {
        scanf("%d%d", &x, &y);
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    sort(ALL(v));
    vector<int> ans(n);
    int cnt = 0, now = 0;
    REP(i, n) {
        now++;
        x = cnt;
        for (int to : g[v[i].second]) {
            if (v[i].first > a[to]) x--;
        }
        ans[v[i].second] = x;
        if (i < n - 1 && v[i].first < v[i + 1].first) {
            cnt += now;
            now = 0;
        }
    }
    REP(i, n) printf("%d ", ans[i]);
    printf("\n");
    return 0;
}
