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

const int N = 16;
int a[N][N];
ll group[1 << N], dp[1 << N];

int main() {
    int n;
    cin >> n;
    REP(i, n) REP(j, n) cin >> a[i][j];
    for (int mask = 1; mask < (1 << n); mask++) {
        REP(i, n) REPP(j, i + 1, n) {
            if ((mask & (1 << i)) && (mask & (1 << j))) {
                group[mask] += a[i][j];
            }
        }
    }
    dp[0] = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        int prev = mask;
        while (true) {
            prev = (prev - 1) & mask;
            dp[mask] = max(dp[mask], dp[prev] + group[mask - prev]);
            if (prev == 0) break;
        }
    }
    cout << dp[(1 << n) - 1] << endl;
    return 0;
}
