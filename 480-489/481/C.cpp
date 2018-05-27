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
typedef pair<ll, ll> pll;

const int maxn = 2e5 + 5;
int n, m;
ll a[maxn], sum[maxn];

pll solve(ll nb) {
    ll x = lower_bound(sum, sum + n, nb) - sum;
    assert(x > 0);
    ll y = nb - sum[x - 1];
    return MP(x, y);
}

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) scanf("%lld", a + i);
    REP(i, n) sum[i + 1] = sum[i] + a[i];
    ll x;
    REP(i, m) {
        scanf("%lld", &x);
        pll ans = solve(x);
        printf("%lld %lld\n", ans.first, ans.second);
    }
    return 0;
}
