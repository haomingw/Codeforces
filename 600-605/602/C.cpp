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
  int n, k;
  scanf("%d%d", &n, &k);
  string s;
  cin >> s;
  string t = "";
  REP(i, k - 1) t += "()";
  int m = n - 2 * (k - 1);
  REP(i, m / 2) t.push_back('(');
  REP(i, m / 2) t.push_back(')');
  printf("%d\n", n);
  int p;
  REP(i, n) {
    if (s[i] == t[i]) printf("%d %d\n", i + 1, i + 1);
    else {
      p = i;
      while (p < n && t[i] != s[p]) p++;
      p++;
      printf("%d %d\n", i + 1, p);
      reverse(s.begin() + i, s.begin() + p);
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
