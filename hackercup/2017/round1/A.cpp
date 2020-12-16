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

const int inf = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > a(n);
    REP(i, n) REP(j, m) {
        int x; cin >> x;
        a[i].push_back(x);
    }
    REP(i, n) sort(ALL(a[i]));
    int dp[n + 1][n + 1];
    REP(i, n + 1) REP(j, n + 1) dp[i][j] = inf;
    dp[0][0] = 0;
    REPP(i, 1, n + 1) REP(j, n + 1) {
        if (i > j) continue;
        REP(k, m + 1)  {
            if (j >= k) {
                int add = k * k;
                REP(l, k) add += a[i - 1][l]; // from 1 base to 0 base
                dp[i][j] = min(dp[i][j], dp[i - 1][j - k] + add);
            }
        }
    }
    cout << dp[n][n] << endl;
}

int main() {
    int T; cin >> T;
    REP(i, T) {
        printf("Case #%d: ", i + 1);
        solve();
    }
    return 0;
}
