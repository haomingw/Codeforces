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

const int maxn = 1005;
const int digits = 51;
ll a[maxn];
int d[digits];

void solve() {
  memset(d, 0, sizeof(d));
  int n;
  ll m;
  cin >> n >> m;
  REP(i, n) cin >> a[i];
  ll target = -m;
  REP(i, n) target += a[i];
  REP(k, digits) REP(i, n) {
    if ((1LL << k) & a[i]) d[k]++;
  }
  REP(k, digits) d[k] = n - 2 * d[k];
  ll best_after = 0;
  REP(k, digits) if (d[k] < 0) best_after += (1LL << k) * d[k];
  if (target + best_after > 0) {
    cout << -1 << endl;
    return;
  }
  ll ans = 0;
  PER(k, digits) {
    ll now = (1LL << k) * d[k];
    best_after = 0;
    REP(i, k) if (d[i] < 0) best_after += (1LL << i) * d[i];
    if (target + now + best_after <= 0) {
      ans += 1LL << k;
      target += now;
    }
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
