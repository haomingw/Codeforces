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

int x, y, z;

int to_int(string s) {
    int a = 0;
    REP(i, SIZE(s)) a = a * 10 + s[i] - '0';
    return a;
}

void parse(string s) {
    int n = s.size(), ind, ind1 = -1, sign = 1;
    REP(i, n) {
        if (s[i] == 'd') ind = i;
        if (s[i] == '+') ind1 = i;
        if (s[i] == '-') sign = -1, ind1 = i;
    }
    x = to_int(s.substr(0, ind));
    if (ind1 < 0) {
        y = to_int(s.substr(ind + 1));
        z = 0;
    } else {
        y = to_int(s.substr(ind + 1, ind1 - ind - 1));
        z = to_int(s.substr(ind1 + 1));
    }
    z *= sign;
}

const int maxn = 405;

void solve() {
    int h, n;
    cin >> h >> n;
    double ans = 0.0;
    double dp[maxn][maxn];
    REP(_, n) {
        REP(i, maxn) REP(j, maxn) dp[i][j] = 0.0;
        string s; cin >> s;
        parse(s);
        int t = h - z; dp[0][0] = 1.0;
        REPP(i, 1, x + 1) {
            REPP(j, i, i * y + 1) {
                REPP(k, 1, y + 1) if (j >= k) dp[i][j] += dp[i - 1][j - k] / y;
            }
        }
        double tmp = 0.0;
        REPP(i, x, x * y + 1) if(i >= t) tmp += dp[x][i];
        ans = max(ans, tmp);
    }
    printf("%.8f\n", ans);
}

int main() {
    int T; cin >> T;
    REP(i, T) {
        printf("Case #%d: ", i + 1);
        solve();
    }
    return 0;
}
