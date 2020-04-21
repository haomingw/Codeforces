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
#include <random>
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

const int R = 1e9;
int t, a, b;

void solve() {
  mt19937 rng(58);
  bool ok = false;
#ifdef LOCAL
  int radius = rng() % (b - a + 1) + a;
  int cx = rng() % (2 * (R - radius) + 1) - (R - radius);
  int cy = rng() % (2 * (R - radius) + 1) - (R - radius);
#endif
  auto query = [&](int x, int y) {
#ifdef LOCAL
    if (x == cx && y == cy) {
      ok = true;
      return (string) "CENTER";
    }
    if (1LL * (x - cx) * (x - cx) + 1LL * (y - cy) * (y - cy) <= 1LL * radius * radius)
      return (string) "HIT";
    return (string) "MISS";
#endif
    cout << x << " " << y << endl;
    string verdict;
    cin >> verdict;
    if (verdict == "CENTER") ok = true;
    return verdict;
  };
  while (true) {
    int x = rng() % (2 * R + 1) - R;
    int y = rng() % (2 * R + 1) - R;
    if (query(x, y) == "MISS") continue;
    if (ok) break;
    int xl, xr, yl, yr, l, r;

    l = -R, r = x;
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (query(mid, y) == "MISS") l = mid + 1;
      else r = mid;
    }
    xl = r;

    l = x, r = R;
    while (l < r) {
      int mid = l + (r - l + 1) / 2;
      if (query(mid, y) == "MISS") r = mid - 1;
      else l = mid;
    }
    xr = l;

    l = -R, r = y;
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (query(x, mid) == "MISS") l = mid + 1;
      else r = mid;
    }
    yl = r;

    l = y, r = R;
    while (l < r) {
      int mid = l + (r - l + 1) / 2;
      if (query(x, mid) == "MISS") r = mid - 1;
      else l = mid;
    }
    yr = l;

    query((xl + xr) / 2, (yl + yr) / 2);
    assert(ok);
    break;
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  cin >> t >> a >> b;
  while (t--) solve();
  return 0;
}
