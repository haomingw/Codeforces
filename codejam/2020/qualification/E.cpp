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
#include <bitset>
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

const int maxn = 55;
int a[maxn][maxn], taken[maxn];
int n, K;

bool dfs2() {
  REP(i, n) REP(j, n) {
    if (a[i][j] > 0) continue;
    vector<int> vis(n + 1);
    REP(k, n) if (a[i][k] > 0) vis[a[i][k]] = 1;
    REP(k, n) if (a[k][j] > 0) vis[a[k][j]] = 1;
    REPP(k, 1, n + 1) if (!vis[k]) {
      a[i][j] = k;
      if (dfs2()) return true;
    }
    a[i][j] = 0;
    return false;
  }
  int trace = 0;
  REP(i, n) trace += a[i][i];
  return trace == K;
}

bool dfs(vector<int>& v, int need) {
  int m = n - v.size();
  if (need < m) return false;
  if (need > m * n) return false;
  if (m == 0) {
    for (int x : v) if (taken[x] == n - 1) return false;
    return true;
  }
  for (int i = 1; i < n + 1; i++) {
    taken[i]++;
    v.push_back(i);
    if (dfs(v, need - i)) return true;
    v.pop_back();
    taken[i]--;
  }
  return false;
}

bool match(int i, vector<vector<int> >& w, vector<int>& r, vector<int>& c, vector<int>& seen) {
  REP(j, n) if (w[i][j] && !seen[j]) {
    seen[j] = 1;
    if (c[j] < 0 || match(c[j], w, r, c, seen)) {
      r[i] = j;
      c[j] = i;
      return true;
    }
  }
  return false;
}

int bipartite_match(vector<vector<int> >& w, vector<int>& r, vector<int>& c) {
  int cnt = 0;
  REP(i, n) {
    vector<int> seen(n);
    if (match(i, w, r, c, seen)) cnt++;
  }
  return cnt;
}

void solve() {
  memset(a, 0, sizeof(a));
  memset(taken, 0, sizeof(taken));
  cin >> n >> K;
  vector<int> choices;
  if (!dfs(choices, K)) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }
  REP(i, n) a[i][i] = choices[i];
  set<int> d;
  for (int x : choices) d.insert(x);
  for (int x : d) {
    vector<vector<int> > w;
    REP(i, n) {
      vector<int> can(n);
      int found = -1;
      REP(j, n) if (a[i][j] == x) found = j;
      if (found >= 0) can[found] = 1;
      else {
        REP(j, n) if (a[i][j] == 0) can[j] = 1;
      }
      w.push_back(can);
    }
    vector<int> r(n, -1), c(n, -1);
    assert(bipartite_match(w, r, c) == n);
    REP(i, n) a[i][r[i]] = x;
  }
  for (int x = 1; x < n + 1; x++) {
    if (d.count(x)) continue;
    vector<vector<int> > w;
    REP(i, n) {
      vector<int> can(n);
      int found = -1;
      REP(j, n) if (a[i][j] == x) found = j;
      if (found >= 0) can[found] = 1;
      else {
        REP(j, n) if (a[i][j] == 0) can[j] = 1;
      }
      w.push_back(can);
    }
    vector<int> r(n, -1), c(n, -1);
    assert(bipartite_match(w, r, c) == n);
    REP(i, n) a[i][r[i]] = x;
  }
  cout << "POSSIBLE" << endl;
  REP(i, n) {
    REP(j, n) cout << a[i][j] << " ";
    cout << endl;
  }
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
