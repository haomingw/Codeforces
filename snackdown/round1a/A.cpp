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

#define REPP(i,a,b) for(int i=(a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)
#define PER(i,a) for(int i = (a) - 1; i >= 0; --i)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

int left(char c) {
    return c == 'd' || c == 'f';
}

void solve() {
    int n; cin >> n;
    map<string, int> mp;
    string s;
    int ans = 0;
    REP(i, n) {
        cin >> s;
        if (mp.count(s)) ans += mp[s] / 2;
        else {
            int m = s.size(), x = 0;
            int prev = left(s[0]) ^ 1;
            REP(j, m) {
                if (left(s[j]) ^ prev) x += 2;
                else x += 4;
                prev = left(s[j]);
            }
            ans += x;
            mp[s] = x;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int T; cin >> T;
    REP(i, T) {
        solve();
    }
    return 0;
}
