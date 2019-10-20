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

const int maxn = 20;
int a[maxn], b[maxn];

void solve() {
  int n, h;
  cin >> n >> h;
  REP(i, n) cin >> a[i];
  REP(i, n) cin >> b[i];
  int m = 1;
  REP(i, n) m *= 3; // m = 3 ^ n
  int ans = 0;
  ll x, y;
  REP(i, m) {
    int base = 1;
    x = y = 0;
    REP(j, n) {
      int state = i / base % 3;
      if (state == 0) x += a[j];
      else if (state == 1) y += b[j];
      else x += a[j], y += b[j];
      base *= 3;
    }
    if (x >= h && y >= h) ans++;
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
