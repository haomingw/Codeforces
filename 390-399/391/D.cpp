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

const int mod = 1e9 + 7;
const int N = 1 << 20;
int dp[77][N];

void add(int& a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}

int main() {
    int n; cin >> n;
    string s; cin >> s;
    REP(i, n) {
        dp[i][0] = 1; // cut begins with this index
        REP(j, N) {
            if (dp[i][j] == 0) continue;
            int x = 0;
            for (int k = i; k < n; k++) {
                x = x * 2 + s[k] - '0';
                if (x > 20) break;
                if (x > 0) {
                    add(dp[k + 1][j | 1 << (x - 1)], dp[i][j]);
                }
            }
        }
    }
    int ans = 0;
    REP(i, n + 1) {
        int r = 1;
        while (r < N) {
            add(ans, dp[i][r]);
            r = 2 * r + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
