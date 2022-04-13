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

const int mod = 998244353;
const int N = 2e5 + 5;
int p[N], q[N], f[N], cnt[N], r[N];
ll dp[N][2][2];

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  REPP(i, 1, n + 1) cin >> p[i];
  REPP(i, 1, n + 1) cin >> q[i];
  REPP(i, 1, n + 1) f[i] = i;
  REPP(i, 1, n + 1) f[find(p[i])] = find(q[i]);
  REPP(i, 1, n + 1) cnt[find(i)]++;
  dp[1][0][0] = 1;
  dp[1][1][1] = 1;
  r[1] = 1;
  for (int i = 2; i < n + 1; i++) {
    REP(j, 2) {
      dp[i][j][0] = dp[i - 1][j][1];
      dp[i][j][1] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % mod;
    }
    r[i] = (dp[i][0][1] + dp[i][1][0] + dp[i][1][1]) % mod;
  }
  int ans = 1;
  REPP(i, 1, n + 1) if (f[i] == i) ans = 1LL * ans * r[cnt[i]] % mod;
  cout << ans << endl;
  return 0;
}
