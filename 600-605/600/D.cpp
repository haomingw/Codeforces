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
vector<int> g[maxn];
bool used[maxn];
pii a[maxn];
int k, mx, ans;

void dfs(int u) {
  used[u] = true;
  mx = max(mx, u);
  for (int v : g[u]) {
    if (!used[v]) dfs(v);
  }
}

void add(pii t) {
  while (k > 0 && t.first < a[k - 1].second) {
    ans++;
    k--;
    t.first = min(t.first, a[k].first);
    t.second = max(t.second, a[k].second);
  }
  a[k++] = t;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int u, v;
  REP(i, m) {
    scanf("%d%d", &u, &v);
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  REP(i, n) {
    if (used[i]) continue;
    mx = -1;
    dfs(i);
    add(MP(i, mx));
  }
  cout << ans << endl;
  return 0;
}
