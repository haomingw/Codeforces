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
  string s;
  cin >> x >> y >> s;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    char c = s[i];
    if (c == 'E') x++;
    else if (c == 'W') x--;
    else if (c == 'N') y++;
    else y--;
    if (abs(x) + abs(y) <= i + 1) {
      cout << i + 1 << endl;
      return;
    }
  }
  cout << "IMPOSSIBLE" << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int T;
  cin >> T;
  REP(i, T) {
    cout << "Case #" << i + 1 << ": ";
    solve();
  }
  return 0;
}
