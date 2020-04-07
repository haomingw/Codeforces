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

int T, b;

void comp(string& s) {
  int n = s.size();
  REP(i, n) {
    if (s[i] == '0') s[i] = '1';
    else s[i] = '0';
  }
}

void rev(string& s) {
  reverse(s.begin(), s.end());
}

int first_asymmetric(string& s) {
  // return index of the first asymmetric char
  int l = 0, r = s.size() - 1;
  while (l < r) {
    if (s[l] != s[r]) return l;
    l++, r--;
  }
  return -1;
}

void query_batch_same(string& s) {
  // 10 queries
  char c;
  cout << 1 << endl;
  cin >> c;
  if (s[0] != c) {
    // either complement or (complement + reverse)
    // need second check
    comp(s);
  }
  int x = first_asymmetric(s);
  x = max(x, 0);
  cout << x + 1 << endl;
  cin >> c;
  if (s[x] != c) rev(s);
}

int first_symmetric(string& s) {
  int l = 0, r = s.size() - 1;
  while (l < r) {
    if (s[l] == s[r]) return l;
    l++, r--;
  }
  return -1;
}

void query_batch_diff(string& s, int k) {
  char c;
  cout << 1 << endl;
  cin >> c;
  if (s[0] != c) {
    // complement or reverse
    comp(s);
  }
  int x = first_symmetric(s);
  if (x == k) x = -1;
  x = max(x, 0);
  cout << x + 1 << endl;
  cin >> c;
  if (s[x] != c) { comp(s); rev(s); }
}

void query(string& s) {
  bool same = (s[0] == s.back());
  int rest = b - 10, k = 5;
  char c;
  while (rest > 0) {
    if (same) query_batch_same(s);
    else query_batch_diff(s, k);
    REPP(i, k, k + 4) {
      cout << i + 1 << endl;
      cin >> c;
      s[i] = c;

      cout << b - i << endl;
      cin >> c;
      s[b - i - 1] = c;
    }
    rest -= 8, k += 4;
  }
}

void solve(int test_case) {
  string s(b, '0');
  char c;
  REP(i, 5) {
    cout << i + 1 << endl;
    cin >> c;
    s[i] = c;

    cout << b - i << endl;
    cin >> c;
    s[b - i - 1] = c;
  }
  query(s);
  cout << s << endl;
  char verdict;
  cin >> verdict;
  if (verdict == 'N' || test_case == T) exit(0);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> T >> b;
  REP(i, T) {
    solve(i + 1);
  }
  return 0;
}
