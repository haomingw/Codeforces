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
int a[maxn], dp[maxn];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    REP(i, n) scanf("%d", a + i);
    memset(dp, inf, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i >= j) {
                dp[i] = min(dp[i], dp[i - j] + abs(a[i] - a[i - j]));
            }
        }
    }
    cout << dp[n - 1] << endl;
    return 0;
}
