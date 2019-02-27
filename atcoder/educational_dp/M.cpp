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

const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
int a[105], dp[105][maxn];

void add(int& a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}

void sub(int& a, int b) {
    a -= b;
    if (a < 0) a += mod;
}

int main() {
    int n, k;
    cin >> n >> k;
    REP(i, n) cin >> a[i];
    REP(i, n + 1) dp[i][0] = 1;
    REP(i, k + 1) dp[0][i] = 1;
    REPP(i, 1, n + 1) REPP(j, 1, k + 1) {
        add(dp[i][j], dp[i][j - 1]);
        add(dp[i][j], dp[i - 1][j]);
        sub(dp[i][j], j > a[i - 1] ? dp[i - 1][j - a[i - 1] - 1] : 0);
    }
    int ans = dp[n][k];
    sub(ans, dp[n][k - 1]);
    cout << ans << endl;
    return 0;
}
