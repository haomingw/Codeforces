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
int n, a[maxn];

int calc(int t=inf) {
    int prev = -1, pos = 0;
    if (t < inf) {
        REP(i, n) if (a[i] > 0) {
            if (prev > 0) {
                if ((a[i] - prev + t) % t != (i - pos) % t || a[i] > t)
                    return -1;
            }
            prev = a[i], pos = i;
        }
        return t;
    }
    REP(i, n) if (a[i] > 0) {
        if (prev == -1 || a[i] - prev == i - pos) {
            prev = a[i], pos = i;
            continue;
        }
        if (a[i] - prev > i - pos) return -1;
        // t - prev + k * t + a[i] == i - pos
        bool found = false;
        REPP(j, prev, i - pos + prev - a[i] + 1) {
            int x = j - prev + a[i], tt = -1;
            if (i - pos < x) tt = -1;
            else if ((i - pos - x) % j == 0) tt = calc(j), found = true;
            t = t == inf ? tt : max(t, tt);
        }
        if (!found) t = -1;
        break;
    }
    return t;
}

void solve() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    int t = calc();
    if (t == -1) cout << "impossible" << endl;
    else cout << (t == inf ? "inf" : to_string(t)) << endl;
}

int main() {
    int T; cin >> T;
    REP(i, T) {
        solve();
    }
    return 0;
}
