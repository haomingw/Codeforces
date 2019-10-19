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

#define REPP(i,a,b) for(int i=(a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)
#define PER(i,a) for(int i = (a) - 1; i >= 0; --i)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 1e5 + 5;
int dp[maxn];
bool bad[maxn];

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  int x;
  fill(dp, dp + n + 1, -1);
  fill(bad, bad + n + 1, false);
  REP(i, m) {
    cin >> x;
    bad[x] = true;
  }
  ll ans = 0;
  while (q--) {
    cin >> x;
    if (dp[x] != -1) {
      ans += dp[x];
      continue;
    }
    dp[x] = 0;
    for (int i = x; i <= n; i += x) {
      if (!bad[i]) dp[x]++;
    }
    ans += dp[x];
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int T;
  cin >> T;
  REP(i, T) {
    cout << "Case #" << i + 1 << ": ";
    solve();
  }
  return 0;
}
