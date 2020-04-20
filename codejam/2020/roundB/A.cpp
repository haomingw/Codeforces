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
  int x, y;
  cin >> x >> y;
  if ((x + y) % 2 == 0) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }
  int l = 0;
  while ((1 << l) <= (abs(x) + abs(y)) / 2) l++;
  string s;
  for (int i = l; i >= 0; i--) {
    if (abs(x) > abs(y)) {
      if (x > 0) {
        x -= 1 << i;
        s.push_back('E');
      } else {
        x += 1 << i;
        s.push_back('W');
      }
    } else {
      if (y > 0) {
        y -= 1 << i;
        s.push_back('N');
      } else {
        y += 1 << i;
        s.push_back('S');
      }
    }
  }
  reverse(s.begin(), s.end());
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
