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

const int maxn = 1e5 + 5;
int a[maxn];
bool used[maxn];

void solve() {
  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%d", a + i);
  memset(used, 0, sizeof(used));
  int prev = -1;
  vector<int> ans;
  int p = 1;
  REP(i, n) {
    if (a[i] > prev) {
      ans.push_back(a[i]);
      used[a[i]] = true;
    } else {
      while (p < a[i] && used[p]) p++;
      if (p == a[i]) {
        puts("-1");
        return;
      }
      ans.push_back(p);
      used[p] = true;
    }
    prev = a[i];
  }
  for (int x : ans) printf("%d ", x);
  printf("\n");
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
