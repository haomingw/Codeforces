#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

#define REPP(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, a) for (int i = 0; i < (a); ++i)
#define PER(i, a) for (int i = (a)-1; i >= 0; --i)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 5;
int a[N], dp[N][2][2];

int main() {
  int n, x, y;
  cin >> n >> x >> y;
  REP(i, n) cin >> a[i + 1];
  ll ans = 0;
  for (int i = 1; i < n + 1; i++) {
    if (a[i] > x || a[i] < y) continue;
    int hx = a[i] == x, hy = a[i] == y;
    dp[i][hx][hy] = 1;
    REP(p, 2) REP(q, 2) dp[i][p | hx][q | hy] += dp[i - 1][p][q];
    ans += dp[i][1][1];
  }
  cout << ans << endl;
  return 0;
}
