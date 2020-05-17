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
  int a, b, c, d;
  scanf("%d%d%d%d", &a, &b, &c, &d);
  ll ans = 0;
  a -= b, ans += b;
  if (a <= 0) {
    cout << ans << endl;
    return;
  }
  if (c <= d) {
    cout << -1 << endl;
    return;
  }
  int k = c - d;
  ans += 1LL * (a + k - 1) / k * c;
  cout << ans << endl;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
