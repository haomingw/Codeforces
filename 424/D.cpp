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

const int inf = 2e9 + 5;
const int maxn = 2005;
int a[maxn], b[maxn], dp[maxn][maxn];

int dist(int person, int key, int office) {
    return abs(person - key) + abs(key - office);
}

int main() {
    int n, k, p, t;
    scanf("%d%d%d", &n, &k, &p);
    REP(i, n) scanf("%d", &a[i]);
    REP(i, k) scanf("%d", &b[i]);
    sort(a, a + n);
    sort(b, b + k);
    REP(i, maxn) REP(j, maxn) dp[i][j] = inf;
    dp[0][0] = 0;
    REP(i, n + 1) REP(j, k + 1) {
        dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
        if (i < n && j < k)
            dp[i + 1][j + 1] = min(dp[i + 1][j + 1], max(dp[i][j], dist(a[i], b[j], p)));
    }
    cout << dp[n][k] << endl;
    return 0;
}



