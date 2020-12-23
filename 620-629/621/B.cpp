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

const int maxn = 1e5 + 5;
int a[maxn];

void solve() {
  int n, x;
  scanf("%d%d", &n, &x);
  int mx = 0, ok = 0;
  REP(i, n) {
    scanf("%d", a + i);
    mx = max(mx, a[i]);
    if (a[i] == x) ok = 1;
  }
  if (ok) {
    cout << 1 << endl;
    return;
  }
  int ans = max((x + mx - 1) / mx, 2);
  cout << ans << endl;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
