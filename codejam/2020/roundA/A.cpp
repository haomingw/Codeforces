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

void solve() {
  int n;
  cin >> n;
  vector<string> vs(n);
  for (string& s : vs) cin >> s;
  string pref = "", suf = "";
  vector<string> sub;
  bool ok = true;
  for (string& s : vs) {
    int m = s.size(), prev = -1;
    REP(i, m) if (s[i] == '*') {
      if (prev == -1) {
        string other_pref = s.substr(0, i);
        if (other_pref.size() > pref.size()) swap(pref, other_pref);
        if (pref.substr(0, other_pref.size()) != other_pref) {
          ok = false;
          break;
        }
      } else {
        sub.push_back(s.substr(prev + 1, i - prev - 1));
      }
      prev = i;
    }
    if (!ok) break;
    string other_suf = s.substr(prev + 1);
    if (other_suf.size() > suf.size()) swap(suf, other_suf);
    if (suf.substr(suf.size() - other_suf.size()) != other_suf) {
        ok = false;
        break;
    }
  }
  if (!ok) cout << "*" << endl;
  else {
    cout << pref;
    for (string& s : sub) cout << s;
    cout << suf << endl;
  }
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
