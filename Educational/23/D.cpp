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
#define SIZE(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int inf = 1e9;
const int maxn = 1e6 + 5;
int n, a[maxn], l[maxn], r[maxn], st[maxn];

ll solve() {
    ll res = 0;
    int top = 0; a[0] = inf, st[0] = 0;
    // find rightmost maximum value
    REPP(i, 1, n + 1) {
        for (; a[i] >= a[st[top]]; top--);
        l[i] = st[top];
        st[++top] = i;
    }
    top = 0, a[n + 1] = inf, st[0] = n + 1;
    for (int i = n; i > 0; i--) {
        for (; a[i] > a[st[top]]; top--);
        r[i] = st[top];
        st[++top] = i;
    }
    REPP(i, 1, n + 1) {
        res += 1LL * (i - l[i]) * (r[i] - i) * a[i];
    }
    return res;
}

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i + 1);
    ll ans = solve();
    REPP(i, 1, n + 1) a[i] *= -1;
    ans += solve();
    cout << ans << endl;
    return 0;
}
