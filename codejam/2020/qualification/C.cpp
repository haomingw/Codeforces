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

void solve() {
  int n;
  cin >> n;
  vector<pair<pii, int> > v;
  int l, r;
  REP(i, n) {
    cin >> l >> r;
    v.emplace_back(MP(l, r), i);
  }
  sort(v.begin(), v.end());
  int a = 0, b = 0;
  string s = string(n, '?');
  for (auto& pp : v) {
    int low = pp.first.first;
    int high = pp.first.second;
    int id = pp.second;
    if (a <= low) {
      s[id] = 'C';
      a = high;
    } else if (b <= low) {
      s[id] = 'J';
      b = high;
    } else {
      cout << "IMPOSSIBLE" << endl;
      return;
    }
  }
  cout << s << endl;
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
