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
#define REPP(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)
#define PER(i,a) for(int i = (a) - 1; i >= 0; --i)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 1e5 + 5;
int a[maxn], b[maxn];

bool solve() {
  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%d", a + i);
  REP(i, n) scanf("%d", b + i);
  int l = n - 1, r = 0;
  REP(i, n) {
    if (a[i] != b[i]) {
      l = min(l, i);
      r = max(r, i);
    }
  }
  int diff = a[r] - b[r];
  if (diff > 0) {
    return false;
  }
  REPP(i, l, r) {
    if (a[i] - b[i] != diff) {
      return false;
    }
  }
  return true;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    if (solve()) puts("YES");
    else puts("NO");
  }
  return 0;
}
