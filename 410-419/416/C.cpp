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
#define SIZE(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int inf = 2e9;
const int maxn = 5005;
int a[maxn], le[maxn], ri[maxn], dp[maxn];
bool used[maxn];

int main() {
    int n;
    cin >> n;
    REP(i, maxn) le[i] = inf, ri[i] = -inf;
    REP(i, n) {
        cin >> a[i];
        le[a[i]] = min(le[a[i]], i);
        ri[a[i]] = max(ri[a[i]], i);
    }
    REP(i, n + 1) dp[i] = -inf;
    dp[0] = 0;
    REP(i, n) {
        dp[i + 1] = max(dp[i + 1], dp[i]);
        int l = i, r = i;
        memset(used, false, sizeof(used));
        int sum = 0;
        for (int j = l; j <= r; j++) {
            l = min(l, le[a[j]]);
            r = max(r, ri[a[j]]);
            if (!used[a[j]]) {
                used[a[j]] = true;
                sum ^= a[j];
            }
        }
        if (l == i) {
            dp[r + 1] = max(dp[r + 1], dp[l] + sum);
        }
    }
    cout << dp[n] << endl;
    return 0;
}
