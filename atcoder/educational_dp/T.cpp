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
const int maxn = 3005;
int dp[maxn][maxn], sum[maxn];

void add(int& a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    dp[1][1] = 1;
    REPP(len, 2, n + 1) {
        memset(sum, 0, sizeof(sum));
        REPP(i, 1, len) sum[i] = (sum[i - 1] + dp[len - 1][i]) % mod;
        REPP(i, 1, len + 1) {
            int l, r;
            if (s[len - 2] == '<') l = 1, r = i - 1;
            else l = i, r = len - 1;
            add(dp[len][i], (sum[r] - sum[l - 1] + mod) % mod);
        }
    }
    int ans = 0;
    REPP(i, 1, n + 1) add(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}
