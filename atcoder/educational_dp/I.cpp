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

const int maxn = 3005;
double a[maxn], dp[2][maxn];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    REP(i, n) cin >> a[i + 1];
    dp[0][0] = 1;
    int prev = 0;
    REPP(i, 1, n + 1) {
        REPP(j, 0, i + 1) {
            dp[prev ^ 1][j] = 0;
            if (j > 0) dp[prev ^ 1][j] += dp[prev][j - 1] * a[i];
            dp[prev ^ 1][j] += dp[prev][j] * (1 - a[i]);
        }
        prev ^= 1;
    }
    double ans = 0;
    for (int i = n / 2 + 1; i <= n; i++) ans += dp[1][i];
    printf("%.10f\n", ans);
    return 0;
}
