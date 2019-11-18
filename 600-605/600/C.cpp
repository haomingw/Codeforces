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

const int maxn = 2e5 + 5;
ll a[maxn];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  REP(i, n) scanf("%lld", a + i);
  sort(a, a + n);
  ll ans = 0;
  REP(i, n) {
    if (i >= m) a[i] += a[i - m];
    ans += a[i];
    printf("%lld ", ans);
  }
  puts("");
  return 0;
}
