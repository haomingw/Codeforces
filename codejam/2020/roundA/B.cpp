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

void print(int a, int b) {
  cout << a << " " << b << '\n';
}

void solve() {
  int n;
  cin >> n;
  cout << endl;
  if (n <= 500) {
    REP(i, n) print(i + 1, 1);
    return;
  }
  int rest = 30, check = 0;
  int k = n - rest, base = 1;
  bool start = true;
  vector<pii> v;
  REPP(r, 1, 31) {
    if (k & base) {
      if (start) {
        REP(i, r) v.emplace_back(r, i + 1);
        start = false;
      } else {
        REP(i, r) v.emplace_back(r, r - i);
        start = true;
      }
      check += base;
    } else {
      if (start) v.emplace_back(r, 1);
      else v.emplace_back(r, r);
      rest--;
      check++;
    }
    base <<= 1;
  }
  assert(check == n - rest);
  REP(i, rest) {
    if (start) v.emplace_back(31 + i, 1);
    else v.emplace_back(31 + i, 31 + i);
  }
  for (auto& p : v) print(p.first, p.second);
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
