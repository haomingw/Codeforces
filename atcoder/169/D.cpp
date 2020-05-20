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
#include <unordered_map>
#include <bitset>
#include <numeric>
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

int main() {
  ll n;
  cin >> n;
  int ans = 0;
  for (int i = 2; ; i++) {
    if (1LL * i * i > n) break;
    int cnt = 0;
    while (n % i == 0) n /= i, cnt++;
    if (cnt == 0) continue;
    for (int j = 1; j < 10; j++) {
      if (cnt >= j) cnt -= j, ans++;
      else break;
    }
  }
  if (n > 1) ans++;
  cout << ans << endl;
}
