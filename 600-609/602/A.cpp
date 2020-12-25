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
  scanf("%d", &n);
  int l, r;
  int lmax = 0, rmin = 2e9;
  REP(i, n) {
    scanf("%d%d", &l, &r);
    lmax = max(lmax, l);
    rmin = min(rmin, r);
  }
  int ans = max(lmax - rmin, 0);
  cout << ans << endl;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
