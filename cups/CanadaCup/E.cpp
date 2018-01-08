#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <unordered_map>
using namespace std;

#define FOR(i,a,b) for(int i=(a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)
#define PER(i,a) for(int i = (a) - 1; i >= 0; --i)
#define SIZE(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 2e5 + 10;
int a[maxn], pr[maxn];

bool solve(int r, int n) {
    if (r == 0) return true;
    int h = upper_bound(a, a + n, r) - a;
    if (h == 0) return false;
    int l = lower_bound(pr, pr + n + 1, pr[h] - r) - pr;
    r -= pr[h] - pr[l];
    return solve(r, l);
}

int main() {
    int c, n;
    cin >> c >> n;
    REP(i, n) cin >> a[i];
    a[n] = c;
    sort(a, a + n);
    REP(i, n) pr[i + 1] = pr[i] + a[i];

    int ans = maxn;
    for (int i = n; i > 0; i--) {
        for (int j = min(c, a[i]); j >= a[i - 1]; j--) {
            if (!solve(c - j, i)) ans = min(ans, j);
        }
        if (c >= a[i - 1]) c -= a[i - 1];
    }
    if (ans == maxn) return !printf("Greed is good\n");
    else cout << ans << endl;
    return 0;
}
