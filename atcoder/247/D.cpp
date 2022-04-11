#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

#define REPP(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, a) for (int i = 0; i < (a); ++i)
#define PER(i, a) for (int i = (a)-1; i >= 0; --i)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  queue<pii> q;
  REP(i, n) {
    int t, c;
    cin >> t >> c;
    if (t == 1) {
      int x;
      cin >> x;
      q.push(MP(x, c));
    } else {
      ll s = 0;
      while (c) {
        int d = min(q.front().first, c);
        s += 1LL * d * q.front().second;
        q.front().first -= d;
        c -= d;
        if (q.front().first == 0) q.pop();
      }
      cout << s << endl;
    }
  }
  return 0;
}
