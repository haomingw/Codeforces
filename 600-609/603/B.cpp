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

string to_str(int a, int n) {
  string s = to_string(a);
  if (n > SZ(s)) s.insert(0, n - s.size(), '0');
  return s;
}

void add(int& x) {
  if (x % 10 == 9) x -= 9;
  else x++;
}

void solve() {
  int n;
  scanf("%d", &n);
  vector<int> v;
  map<int, int> mp;
  int ans = 0, x;
  REP(i, n) {
    scanf("%d", &x);
    v.push_back(x);
    mp[x]++;
    if (mp[x] > 1) ans++;
  }
  printf("%d\n", ans);
  REP(i, n) {
    if (mp[v[i]] == 1) cout << to_str(v[i], 4) << endl;
    else {
      x = v[i];
      while (mp.count(x)) add(x);
      mp[x]++, mp[v[i]]--;
      cout << to_str(x, 4) << endl;
    }
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
