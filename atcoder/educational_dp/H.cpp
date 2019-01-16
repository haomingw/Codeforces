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
const int maxn = 1005;
int a[maxn][maxn], dp[maxn][maxn];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    string s;
    REP(i, n) {
        cin >> s;
        REP(j, m) a[i + 1][j + 1] = s[j] == '.';
    }
    dp[1][1] = 1;
    REPP(i, 1, n + 1) REPP(j, 1, m + 1) {
        if (i == 1 && j == 1) continue;
        if (a[i][j]) {
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % mod;
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
