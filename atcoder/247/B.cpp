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

const int maxn = 105;
string a[maxn], b[maxn];

int main() {
  int n;
  cin >> n;
  map<string, int> cnt;
  REP(i, n) {
    cin >> a[i] >> b[i];
    cnt[a[i]]++;
    cnt[b[i]]++;
  }
  REP(i, n) {
    if (a[i] == b[i]) {
      if (cnt[a[i]] > 2) {
        cout << "No" << endl;
        return 0;
      }
    } else {
      if (cnt[a[i]] > 1 && cnt[b[i]] > 1) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
