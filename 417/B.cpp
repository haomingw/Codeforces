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

int n, m, dp[105][2];
string s[105];

int ldist(int index) {
    int t = 0;
    REP(i, m + 2) if (s[index][i] == '1') t = i;
    return t;
}

int rdist(int index) {
    int t = 0;
    REP(i, m + 2) if (s[index][m + 1 - i] == '1') t = i;
    return t;
}

bool lightOn(int index) {
    REP(i, m + 2) if (s[index][i] == '1') return true;
    return false;
}

int main() {
    cin >> n >> m;
    REP(i, n) cin >> s[n - 1 - i];
    dp[0][1] = m + 1;
    int k = 0;
    REP(i, n) if (lightOn(i)) k = i;
    REP(i, k) {
        dp[i + 1][0] = min(dp[i][0] + 1 + 2 * ldist(i), dp[i][1] + m + 2);
        dp[i + 1][1] = min(dp[i][1] + 1 + 2 * rdist(i), dp[i][0] + m + 2);
    }
    int ans = min(dp[k][0] + ldist(k), dp[k][1] + rdist(k));
    cout << ans << endl;
    return 0;
}
