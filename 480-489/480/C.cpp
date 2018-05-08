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
int n, k, a[maxn];
int g[256];

int main() {
    cin >> n >> k;
    REP(i, n) cin >> a[i];
    REP(i, 256) g[i] = -1;
    REP(i, n) if (g[a[i]] < 0) {
        int l = max(a[i] - k + 1, 0), r = a[i], done = -1;
        REPP(j, l, r + 1) if (g[j] >= 0) done = j;
        if (done >= 0) {
            int cnt = 0;
            for (int j = done; j >= 0; j--) if (g[j] == g[done]) cnt++;
            if (cnt <= k - a[i] + done) REPP(j, done, a[i] + 1) g[j] = g[done];
        }
        if (g[a[i]] >= 0) continue;
        int x = inf;
        REPP(j, l, r + 1) {
            if (g[j] < 0 && j < x) x = j;
        }
        REPP(j, x, r + 1) g[j] = x;
    }
    REP(i, n) cout << g[a[i]] << " "; cout << endl;
    return 0;
}
