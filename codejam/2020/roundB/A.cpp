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
  int a, b;
  cin >> a >> b;
  int x = abs(a), y = abs(b);
  string s;
  while (max(x, y) > 1) {
    if (((x ^ y) & 1) == 0) {
      cout << "IMPOSSIBLE" << endl;
      return;
    }
    if (((x / 2) ^ (y / 2)) & 1) {
      // plus 1
      if (x & 1) {
        s.push_back('E');
        x--;
      } else {
        s.push_back('N');
        y--;
      }
    } else {
      // minus 1
      if (x & 1) {
        s.push_back('W');
        x++;
      } else {
        s.push_back('S');
        y++;
      }
    }
    x /= 2, y /= 2;
  }
  if (x == y) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }
  if (x) s.push_back('E');
  if (y) s.push_back('N');
  int n = s.size();
  if (a < 0) {
    REP(i, n) {
      if (s[i] == 'E') s[i] = 'W';
      else if (s[i] == 'W') s[i] = 'E';
    }
  }
  if (b < 0) {
    REP(i, n) {
      if (s[i] == 'N') s[i] = 'S';
      else if (s[i] == 'S') s[i] = 'N';
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
