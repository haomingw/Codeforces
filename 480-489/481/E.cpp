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
const int maxn = 1005;
int n, w, a[maxn], b[maxn];

int main() {
    cin >> n >> w;
    REP(i, n) cin >> a[i];
    REP(i, n) b[i + 1] = b[i] + a[i];
    REPP(i, 1, n + 1) if (abs(b[i]) > w) return !printf("0\n");
    int minx = inf, maxx = -inf;
    REPP(i, 1, n + 1) if (b[i] < minx) minx = b[i];
    REPP(i, 1, n + 1) if (b[i] > maxx) maxx = b[i];
    int l = max(-minx, 0), r = min(w - maxx, w);
    int ans = max(r - l + 1, 0);
    cout << ans << endl;
    return 0;
}
