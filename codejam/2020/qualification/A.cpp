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
  int n;
  cin >> n;
  int k = 0, r = 0, c = 0;
  vector<set<int> > row(n), col(n);
  int x;
  REP(i, n) REP(j, n) {
    cin >> x;
    row[i].insert(x);
    col[j].insert(x);
    if (i == j) k += x;
  }
  REP(i, n) if (SZ(row[i]) < n) r++;
  REP(i, n) if (SZ(col[i]) < n) c++;
  cout << k << " " << r << " " << c << endl;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int T;
  cin >> T;
  REP(i, T) {
    cout << "Case #" << i + 1 << ": ";
    solve();
  }
  return 0;
}
