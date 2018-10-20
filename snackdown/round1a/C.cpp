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

const int maxn = 55;
int a[maxn], f[maxn];

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}

void solve() {
    int n;
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    REP(i, n + 1) f[i] = i;
    REP(i, n) REPP(j, i + 1, n) {
        if (gcd(a[i], a[j]) == 1) f[find(i)] = find(j);
    }
    vector<int> v;
    REP(i, n) v.push_back(find(i));
    sort(ALL(v));
    v.resize(unique(ALL(v)) - v.begin());
    int ans  = min(SZ(v) - 1, 1);
    printf("%d\n", ans);
    if (ans) {
        if (a[0] != 47) a[0] = 47;
        else a[0] = 43;
    }
    REP(i, n) printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int T; cin >> T;
    REP(i, T) {
        solve();
    }
    return 0;
}
