#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
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

const int maxn = 305;
int inf = 2e9;
int dp[maxn][maxn];

int prefix(string& a, string& b) {
    int cnt = 0, len = min(SIZE(a), SIZE(b));
    REP(i, len) {
        if (a[i] == b[i]) cnt++;
        else break;
    }
    return cnt;
}

int solve(int n, int k) {
    string s[maxn];
    int l[maxn];
    REP(i, n) cin >> s[i];
    sort(s, s + n);
    REP(i, maxn) REP(j, maxn) dp[i][j] = inf;
    REP(i, n) l[i] = SIZE(s[i]);
    REP(i, n) dp[i][1] = l[i] + 1;

    int ans = inf, tmp;
    REP(i, n) REPP(j, i + 1, n) REPP(kk, 1, k) {
        tmp = dp[i][kk] + l[i] + l[j] - 2 * prefix(s[i], s[j]) + 1;
        dp[j][kk + 1] = min(dp[j][kk + 1], tmp);
    }
    REP(i, n) {
        tmp = dp[i][k] + SIZE(s[i]);
        ans = min(ans, tmp);
    }
    return ans;
}

int main() {
    int T, N, K;
    cin >> T;
    REP(t, T) {
        cin >> N >> K;
        const clock_t begin_time = clock();
        cout << "Case #" << t + 1 << ": " << solve(N, K) << endl;
        clog << "Case #" << t + 1 << ", time: "
             << float( clock () - begin_time ) /  CLOCKS_PER_SEC * 1000 << "ms" << endl;
    }
    return 0;
}
