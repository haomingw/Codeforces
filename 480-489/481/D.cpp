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
const int maxn = 1e5 + 5;
int a[maxn];

int main() {
    int n; cin >> n;
    REP(i, n) cin >> a[i];
    if (n < 3) return !printf("0\n");
    int ans = inf;
    int d[3] = {0, 1, -1};
    REP(i, 3) REP(j, 3) {
        int x = d[i], y = d[j];
        a[0] += x, a[1] += y;
        int diff = a[1] - a[0], cnt = abs(x) + abs(y);
        bool ok = true;
        REP(k, n) {
            int t = abs(a[k] - (a[0] + k * diff));
            if (t > 1) ok = false;
            cnt += t;
        }
        if (ok) ans = min(ans, cnt);
        a[0] -= x, a[1] -= y;
    }
    cout << (ans == inf ? -1 : ans) << endl;
    return 0;
}
