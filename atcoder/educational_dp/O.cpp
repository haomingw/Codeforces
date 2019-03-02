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
const int N = 25;
int a[N][N], dp[1 << N];

void add(int& x, int y) {
    x += y;
    if (x >= mod) x -= mod;
}

int main() {
    int n;
    cin >> n;
    REP(i, n) REP(j, n) cin >> a[i][j];
    int m = 1 << n, x = 0;
    dp[0] = 1;
    REP(mask, m - 1) {
        x = 0;
        REP(i, n) if (mask & (1 << i)) x++;
        REP(i, n) if (!(mask & (1 << i)) && a[x][i]) {
            add(dp[mask ^ (1 << i)], dp[mask]);
        }
    }
    cout << dp[m - 1] << endl;
    return 0;
}
