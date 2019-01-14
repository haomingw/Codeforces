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

const int maxn = 3005;
int dp[maxn][maxn];

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    REPP(i, 1, n + 1) REPP(j, 1, m + 1) {
        dp[i][j] = dp[i][j - 1];
        dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        if (s[i - 1] == t[j - 1]) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }
    int x = n, y = m;
    string ans = "";
    while (x && y) {
        if (dp[x - 1][y] == dp[x][y]) x--;
        else if (dp[x][y - 1] == dp[x][y]) y--;
        else {
            ans.push_back(s[x - 1]);
            x--, y--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}
