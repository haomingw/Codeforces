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
  string s;
  cin >> s;
  int n = s.size();
  int ans = n + 1;
  vector<pair<char, int> > v;
  for (char c : s) {
    if (v.empty() || v.back().first != c) v.emplace_back(c, 1);
    else v.back().second++;
  }
  int m = v.size();
  for (int i = 1; i < m - 1; i++) {
    if (v[i - 1].first != v[i + 1].first)
      ans = min(ans, v[i].second + 2);
  }
  cout << (ans > n ? 0 : ans) << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
