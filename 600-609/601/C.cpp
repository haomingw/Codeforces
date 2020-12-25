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
int cnt[maxn];

int main() {
  int n;
  scanf("%d", &n);
  int a, b, c;
  map<pii, vector<int> > mp;
  REP(i, n - 2) {
    scanf("%d%d%d", &a, &b, &c);
    cnt[a]++, cnt[b]++, cnt[c]++;
    // sort [a, b, c]
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);
    mp[MP(a, b)].push_back(c);
    mp[MP(a, c)].push_back(b);
    mp[MP(b, c)].push_back(a);
  }
  vector<int> once, twice;
  REPP(i, 1, n + 1) {
    if (cnt[i] == 1) once.push_back(i);
    else if (cnt[i] == 2) twice.push_back(i);
  }
  vector<int> ans;
  a = once[0];
  ans.push_back(a);
  pii p;
  for (int x : twice) {
    if (a > x) p = MP(x, a);
    else p = MP(a, x);
    if (mp.count(p)) {
      ans.push_back(x);
      break;
    }
  }
  REP(i, n - 2) {
    a = ans[i], b = ans[i + 1];
    if (a > b) swap(a, b);
    vector<int> v = mp[MP(a, b)];
    if (v.size() == 1) {
      ans.push_back(v[0]);
    } else {
      if (v[0] != ans[i - 1]) ans.push_back(v[0]);
      else ans.push_back(v[1]);
    }
  }
  for (int x : ans) printf("%d ", x);
  puts("");
  return 0;
}
