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

const int N = 1e4;

void solve() {
  int u;
  cin >> u;
  ll q;
  string r;
  vector<int> used(26);
  vector<int> cnt(26);
  REP(i, N) {
    cin >> q >> r;
    for (char c : r) used[c - 'A'] = 1;
    // count most significant digit
    cnt[r[0] - 'A']++;
  }
  REP(i, 26) if (used[i] && !cnt[i]) cout << char(i + 'A');
  vector<pii> digits;
  REP(i, 26) if (cnt[i]) digits.emplace_back(cnt[i], i);
  sort(digits.begin(), digits.end());
  reverse(digits.begin(), digits.end());
  assert(SZ(digits) == 9);
  for (pii& p : digits) cout << char(p.second + 'A');
  cout << endl;
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
