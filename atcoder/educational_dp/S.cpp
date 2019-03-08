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
const int maxn = 105;
int dp[maxn][2], pd[maxn][2];

void add(int& a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}

int main() {
    string s;
    int d;
    cin >> s >> d;
    int n = s.size();
    pd[0][0] = 1;
    REP(i, n) {
        memset(dp, 0, sizeof(dp));
        REP(j, d) REP(can_bigger, 2) REP(digit, 10) {
            if (digit > s[i] - '0' && !can_bigger) break;
            int x = can_bigger || (digit < s[i] - '0');
            add(dp[(j + digit) % d][x], pd[j][can_bigger]);
        }
        REP(j, d) REP(k, 2) pd[j][k] = dp[j][k];
    }
    int ans = (dp[0][0] + dp[0][1] - 1 + mod) % mod;
    cout << ans << endl;
    return 0;
}
