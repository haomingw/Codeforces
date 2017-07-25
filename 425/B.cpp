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
#include <cassert>
using namespace std;

#define REPP(i,a,b) for(int i=(a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)
#define PER(i,a) for(int i = (a) - 1; i >= 0; --i)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

int n, m, cnt;
string s, t;
map<char, bool> good;

bool solve() {
    if (n - cnt > m) return false;
    int k = m - n + cnt, ptr = 0;
    REP(i, m) {
        if (s[ptr] == '?') {
            if (!good[t[i]]) return false;
        } else if (s[ptr] == '*') {
            REP(j, k) if (good[t[i + j]]) return false;
            i += k - 1;
        } else if (s[ptr] != t[i])
            return false;
        ptr++;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> s;
    REP(i, s.size()) good[s[i]] = true;
    int q;
    cin >> s >> q;
    n = s.size();
    REP(i, n) if (s[i] == '*') cnt++;
    while (q--) {
        cin >> t; m = t.size();
        cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}
