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

const int maxn = 30;

int main() {
    int n, c;
    cin >> n >> c;
    int w[n], v[n];
    REP(i, n) scanf("%d%d", &w[i], &v[i]);
    int dp[maxn][maxn];
    REP(i, n + 1) REP(j, c + 1) {
        dp[i][j] = (i == 0) ? 0 : dp[i - 1][j];
        if (i > 0 && j >= w[i - 1]) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
        }
    }
    cout << dp[n][c] << endl;
}
