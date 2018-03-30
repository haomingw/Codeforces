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

const int maxn = 1e5 + 5;
int n, u, a[maxn];

int main() {
    scanf("%d%d", &n, &u);
    REP(i, n) scanf("%d", a + i);
    double ans = -1;
    REP(i, n - 2) {
        int x = upper_bound(a, a + n, a[i] + u) - a - 1;
        if ( x - i < 2) continue;
        ans = max(ans, double(a[x] - a[i + 1]) / (a[x] - a[i]));
    }
    printf("%.12f\n", ans);
    return 0;
}
