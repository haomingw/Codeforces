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
int a[maxn], h[maxn];
ll tree[maxn * 4];

int main() {
    int n;
    scanf("%d", &n);
    REP(i, n) scanf("%d", h + i);
    REP(i, n) scanf("%d", a + i);
    // base: smallest power of 2 that is larger that n
    // [0, n] has n + 1 values
    int base = 1;
    while (base <= n) {
        base *= 2;
    }
    ll ans = 0;
    REP(i, n) {
        ll best = 0;
        int x = base + h[i];
        while (x > 1) {
            if (x & 1) best = max(best, tree[x - 1]);
            x /= 2;
        }
        ans = max(ans, best + a[i]);
        for (int j = base + h[i]; j >= 1; j /= 2) {
            tree[j] = max(tree[j], best + a[i]);
        }
    }
    cout << ans << endl;
    return 0;
}
