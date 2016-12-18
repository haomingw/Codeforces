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

const int maxn = 1010;
bool used[maxn];
int f[maxn], size[maxn];

int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}

int calc(int x) {
    return x * (x - 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k, ans = 0;
    scanf("%d%d%d", &n, &m, &k);
    vector<int> gov;
    REP(i, k) {
        int c; scanf("%d", &c); c--;
        gov.push_back(c);
    }
    REP(i, n) f[i] = i, size[i] = 0;
    int u, v, rest = n, maxt = 0;
    REP(i, m) {
        scanf("%d%d", &u, &v);
        u--, v--;
        f[find(v)] = find(u);
    }
    REP(i, n) size[find(i)]++;
    for (int x : gov) {
        int t = size[find(x)];
        ans += calc(t);
        rest -= t;
        maxt = max(maxt, t);
    }
    ans -= calc(maxt);
    ans += calc(rest + maxt);
    ans -= m;
    cout << ans << endl;
    return 0;
}
