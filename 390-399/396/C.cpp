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

const int inf = 1e9;
const int mod = 1e9 + 7;
int a[30], dp[3][1005];

void add(int& x, int y) {
    x += y;
    if (x >= mod) x -= mod;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    REP(i, 26) cin >> a[i];
    dp[0][0] = 1;
    REPP(i, 1, n + 1) {
        int len = inf;
        dp[1][i] = -inf;
        dp[2][i] = inf;
        for (int j = i - 1; j >= 0; j--) {
            len = min(len, a[s[j] - 'a']);
            if (len < i - j) break;
            add(dp[0][i], dp[0][j]);
            dp[1][i] = max(dp[1][i], max(dp[1][j], i - j));
            dp[2][i] = min(dp[2][i], dp[2][j] + 1);
        }
    }
    cout << dp[0][n] << endl;
    cout << dp[1][n] << endl;
    cout << dp[2][n] << endl;
    return 0;
}
