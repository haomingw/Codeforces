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

void dfs(int x) {
  if (x == 0) return;
  dfs(x - 1);
  cout << x << " ";
  dfs(x - 1);
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  dfs(n);
  return 0;
}
