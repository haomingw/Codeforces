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

const int maxn = 405;
const ll inf = 1e18;
int a[maxn];
ll b[maxn], dp[maxn][maxn];

int main() {
    int n;
    cin >> n;
    REP(i, n) cin >> a[i];
    REP(i, n) b[i + 1] = b[i] + a[i];
    REPP(i, 2, n + 1) REP(j, n + 1 - i) {
        ll x = inf;
        REPP(k, 1, i) x = min(x, dp[j][j + k] + dp[j + k][j + i]);
        dp[j][j + i] = x + b[j + i] - b[j];
    }
    cout << dp[0][n] << endl;
    return 0;
}
