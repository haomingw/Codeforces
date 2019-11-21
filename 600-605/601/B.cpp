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

const int maxn = 1005;
int n, m, a[maxn];

void solve() {
  scanf("%d%d", &n, &m);
  REP(i, n) scanf("%d", a + i);
  if (m < n || n == 2) {
    puts("-1");
    return;
  }
  int cost = 0;
  REP(i, n) cost += 2 * a[i];
  printf("%d\n", cost);
  REP(i, n) {
    printf("%d %d\n", i + 1, (i + 1) % n + 1);
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

