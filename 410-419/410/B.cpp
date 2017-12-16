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
#define SIZE(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

string s[55];

int calc(string a, string b) {
    int n = a.size(), cnt = 0;
    string t = a;
    REP(i, n) {
        if (i > 0) t = t.substr(1) + t[0];
        if (t == b) break;
        else cnt++;
    }
    return cnt == n ? -1 : cnt;
}

int main() {
    int n; cin >> n;
    REP(i, n) cin >> s[i];
    string t = s[0];
    int m = t.size(), ans = 1e9;
    REP(i, m) {
        int cnt = 0;
        t = t.substr(1) + t[0];
        REP(j, n) {
            int x = calc(s[j], t);
            if (x == -1) return !printf("-1\n");
            else cnt += x;
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}
