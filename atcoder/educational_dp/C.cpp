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

const int maxn = 1e5 + 5;
int a[maxn][3], dp[maxn][3];

int main() {
    int n;
    scanf("%d", &n);
    REP(i, n) REP(j, 3) {
        scanf("%d", &a[i][j]);
    }
    REPP(i, 1, n + 1) REP(j, 3) REP(k, 3) {
        if (k != j) dp[i][j] = max(dp[i - 1][k] + a[i - 1][j], dp[i][j]);
    }
    int ans = 0;
    REP(i, 3) ans = max(dp[n][i], ans);
    cout << ans << endl;
    return 0;
}
