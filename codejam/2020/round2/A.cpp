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
  ll left, right;
  cin >> left >> right;
  bool swapped = false;
  if (left < right) {
    swap(left, right);
    swapped = true;
  }
  ll l = 0, r = 2e9;
  while (l < r) {
    ll mid = (l + r + 1) / 2;
    if (mid * (mid + 1) / 2 > left - right) r = mid - 1;
    else l = mid;
  }
  left -= l * (l + 1) / 2;
  if (left == right) swapped = false;
  ll cnt = l;
  l = 0, r = 2e9;
  while (l < r) {
    ll mid = (l + r + 1) / 2;
    if (mid * (cnt + mid + 1) > right) r = mid - 1;
    else l = mid;
  }
  left -= l * (cnt + l);
  right -= l * (cnt + l + 1);
  cnt += 2 * l;
  if (left >= cnt + 1) left -= ++cnt;
  if (swapped) swap(left, right);
  cout << cnt << " " << left << " " << right << endl;
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
