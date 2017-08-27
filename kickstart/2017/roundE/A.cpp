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

const int inf = 1e9;
const int maxn = 105;
int id[maxn][maxn], dp[maxn], appear[maxn * maxn], best[maxn];
map<string, int> mp;

void solve() {
    mp.clear();
    string s, t; cin >> s;
    int n = s.size(), next = 1;
    REP(i, maxn * maxn) appear[i] = inf;
    REP(i, n) {
        t = "";
        REPP(j, i, n) {
            t += s[j];
            if (mp[t] == 0) {
                mp[t] = next++;
            }
            id[i][j - i + 1] = mp[t];
            appear[mp[t]] = min(appear[mp[t]], j);
        }
    }
    REP(i, maxn) dp[i] = inf;
    dp[0] = 0;
    REP(i, n) {
        dp[i + 1] = min(dp[i + 1], dp[i] + 1);
        for (int len = 1; i + len <= n; len++) {
            if (appear[id[i][len]] < i) { // can copy
                fill(best, best + maxn, inf);
                best[i] = dp[i] + 1; // cost of copy
                REPP(j, i, n) {
                    best[j + 1] = min(best[j + 1], best[j] + 1);
                    if (j + len <= n && id[i][len] == id[j][len])
                        best[j + len] = min(best[j + len], best[j] + 1);
                }
                for (int j = i; j <= n; j++)
                    dp[j] = min(dp[j], best[j]);
            }
        }
    }
    cout << dp[n] << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int T; cin >> T;
    REP(i, T) {
        printf("Case #%d: ", i + 1);
        solve();
    }
    return 0;
}
