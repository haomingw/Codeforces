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

void solve() {
  int r, c;
  cin >> r >> c;
  vector<vector<int> > a(r, vector<int>(c));
  REP(i, r) REP(j, c) cin >> a[i][j];
  vector<vector<int> > when(r, vector<int>(c, -1));
  vector<vector<int> > up(r, vector<int>(c));
  vector<vector<int> > down(r, vector<int>(c));
  vector<vector<int> > left(r, vector<int>(c));
  vector<vector<int> > right(r, vector<int>(c));
  REP(i, r) REP(j, c) {
    up[i][j] = i - 1;
    down[i][j] = i + 1;
    left[i][j] = j - 1;
    right[i][j] = j + 1;
  }
  auto get_neighbor = [&](pii p, int dir) {
    int x = p.first, y = p.second;
    if (dir == 0) return MP(up[x][y], y);
    if (dir == 1) return MP(down[x][y], y);
    if (dir == 2) return MP(x, left[x][y]);
    return MP(x, right[x][y]);
  };
  ll total = 0;
  vector<pii> check;
  REP(i, r) REP(j, c) {
    total += a[i][j];
    check.emplace_back(i, j);
  }
  ll ans = total;
  for (int iter = 0; ; iter++) {
    vector<pii> rm;
    for (auto& p : check) {
      int sum = 0, cnt = 0;
      REP(dir, 4) {
        pii q = get_neighbor(p, dir);
        int x = q.first, y = q.second;
        if (min(x, y) >= 0 && x < r && y < c) {
          sum += a[x][y], cnt++;
        }
      }
      if (a[p.first][p.second] * cnt < sum) {
        rm.push_back(p);
      }
    }
    if (rm.empty()) break;
    for (auto& p : rm) {
      total -= a[p.first][p.second];
      when[p.first][p.second] = iter;
    }
    ans += total;
    check.clear();
    for (auto& p : rm) {
      REP(dir, 4) {
        pii q = get_neighbor(p, dir);
        int x = q.first, y = q.second;
        if (min(x, y) >= 0 && x < r && y < c) {
          if (when[x][y] != iter) {
            check.emplace_back(x, y);
            when[x][y] = iter;
          }
        }
      }
    }
    for (auto& p : rm) {
      int i = p.first, j = p.second;
      if (up[i][j] != -1) down[up[i][j]][j] = down[i][j];
      if (down[i][j] != r) up[down[i][j]][j] = up[i][j];
      if (left[i][j] != -1) right[i][left[i][j]] = right[i][j];
      if (right[i][j] != c) left[i][right[i][j]] = left[i][j];
    }
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
