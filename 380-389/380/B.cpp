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

const int inf = 2000;

int main() {
    int n, m;
    cin >> n >> m;
    int a[m], b[m], c[n], d[n], p[n][m];
    fill(a, a + m, inf);
    fill(b, b + m, -1);
    fill(c, c + n, inf);
    fill(d, d + n, -1);
    REP(i, n) REP(j, m) {
        // cin >> p[i][j];
        scanf("%d", &p[i][j]);
        if (p[i][j] == 1) {
            a[j] = min(i, a[j]);
            b[j] = max(i, b[j]);
            c[i] = min(j, c[i]);
            d[i] = max(j, d[i]);
        }
    }
    int ans = 0;
    REP(i, n) REP(j, m) {
        if (p[i][j] == 0) {
            if (i > a[j]) ans++;
            if (i < b[j]) ans++;
            if (j > c[i]) ans++;
            if (j < d[i]) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
