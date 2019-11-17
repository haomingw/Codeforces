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
int a[maxn];

void fail() {
  puts("-1");
  exit(0);
}

int main() {
  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%d", a + i);
  vector<int> ans;
  set<int> people;
  map<int, bool> entered;
  REP(i, n) {
    if (a[i] < 0) {
      if (!people.count(-a[i])) fail();
      people.erase(-a[i]);
      if (people.empty()) {
        ans.push_back(i);
        entered.clear();
      }
    } else {
      if (entered.count(a[i])) fail();
      people.insert(a[i]);
      entered[a[i]] = true;
    }
  }
  if (!people.empty()) fail();
  cout << ans.size() << endl;
  int prev = -1;
  for (int x : ans) {
    cout << x - prev << " ";
    prev = x;
  }
  cout << endl;
  return 0;
}
