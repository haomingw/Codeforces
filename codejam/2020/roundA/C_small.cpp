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

int r, c;

bool eliminated(int x, int y, vector<vector<int> >& a, vector<vector<int> >& used) {
  int total = 0, cnt = 0;
  REPP(i, x + 1, r) if (!used[i][y]) {
    total += a[i][y], cnt++;
    break;
  }
  PER(i, x) if (!used[i][y]) {
    total += a[i][y], cnt++;
    break;
  }
  REPP(j, y + 1, c) if (!used[x][j]) {
    total += a[x][j], cnt++;
    break;
  }
  PER(j, y) if (!used[x][j]) {
    total += a[x][j], cnt++;
    break;
  }
  if (cnt == 0) return false;
  double mean = (double)total / cnt;
  return a[x][y] < mean;
}

void solve() {
  cin >> r >> c;
  vector<vector<int> > v(r, vector<int>(c));
  vector<vector<int> > used(r, vector<int>(c));
  REP(i, r) REP(j, c) cin >> v[i][j];
  ll total = 0;
  while (true) {
    vector<pii> e;
    REP(i, r) REP(j, c) if (!used[i][j]) {
      total += v[i][j];
      if (eliminated(i, j, v, used)) e.emplace_back(i, j);
    }
    if (e.empty()) break;
    for (auto& p : e) used[p.first][p.second] = 1;
  }
  cout << total << endl;
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
