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

const int maxn = 1010;
int f[maxn];

int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}

int main() {
    int n, m, v;
    cin >> n >> m >> v;
    int w[n], b[n];
    REP(i, n) scanf("%d", &w[i]);
    REP(i, n) scanf("%d", &b[i]);
    REP(i, n) f[i] = i;
    int x, y;
    REP(i, m) {
        scanf("%d%d", &x, &y);
        x--, y--;
        f[find(x)] = find(y);
    }
    int dp[maxn], pd[maxn];
    fill(dp, dp + v + 1, 0);
    REP(i, n) if (i == find(i)) {
        vector<int> items;
        int sw = 0, sb = 0;
        REP(j, n) if (i == find(j)){
            items.push_back(j);
            sw += w[j];
            sb += b[j];
        }
        REP(j, v + 1) pd[j] = dp[j];
        for (auto p : items) {
            REPP(j, w[p], v + 1) dp[j] = max(dp[j], pd[j - w[p]] + b[p]);
        }
        REPP(j, sw, v + 1) dp[j] = max(dp[j], pd[j - sw] + sb);
    }
    cout << dp[v] << endl;
    return 0;
}
