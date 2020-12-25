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
#include <bitset>
#include <numeric>
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

ll dp[26][26], a[26], ans;

void solve() {
  string s;
  cin >> s;
  int n = s.size();
  REP(i, n) {
    int x = s[i] - 'a';
    REP(j, 26) dp[x][j] += a[j];
    a[x]++;
  }
  REP(i, 26) REP(j, 26) ans = max(ans, dp[i][j]);
  REP(i, 26) ans = max(ans, a[i]);
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  solve();
  return 0;
}
