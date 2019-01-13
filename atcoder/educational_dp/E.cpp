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
const int inf = 0x3f3f3f3f;
int w[105], v[105];
ll dp[maxn];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    REP(i, n) scanf("%d%d", w + i, v + i);
    memset(dp, inf, sizeof(dp));
    dp[0] = 0;
    REP(i, n) for (int j = maxn; j > 0; j--) {
        if (j >= v[i]) dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
    }
    int ans = 0;
    REP(i, maxn) if (dp[i] <= k) ans = i;
    cout << ans << endl;
    return 0;
}
