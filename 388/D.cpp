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

const int maxn = 2e5 + 10;
int n, k, ordsz, ord[maxn], b[maxn];
bool used[maxn];
vector<int> a[maxn];

void solve() {
    cin >> k;
    REP(i, k) scanf("%d", &b[i]);
    REP(i, k) used[b[i]] = 1;
    int p = 0;
    while (p < ordsz && used[ord[p]]) p++;
    if (p == ordsz) {
        printf("0 0\n");
        return;
    }
    int q = p + 1;
    p = ord[p];
    while (q < ordsz && used[ord[q]]) q++;
    if (q == ordsz) {
        printf("%d %d\n", p, a[p][0]);
        return;
    }
    printf("%d %d\n", p, *lower_bound(ALL(a[p]), a[ord[q]].back()));
    return;
}

int main() {
    cin >> n;
    int x, y;
    REP(i, n) {
        scanf("%d %d", &x, &y);
        ord[i] = x;
        a[x].push_back(y);
    }
    reverse(ord, ord + n);
    REP(i, n) {
        if (used[ord[i]]) continue;
        used[ord[i]] = 1;
        ord[ordsz++] = ord[i];
    }
    REP(i, n + 1) used[i] = 0;
    int q; cin >> q;
    REP(i, q) {
        solve();
        REP(i, k) used[b[i]] = 0;
    }
    return 0;
}
