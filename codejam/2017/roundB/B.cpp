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
typedef pair<int, char> pic;

int r, o, y, g, b, v, cnt[3];
string s;

vector<int> build(int a, int b, int c) {
    vector<int> vv(a, 0);
    int t = a;
    REP(i, b) {
        int n = vv.size();
        if (t == 0) {
            REP(j, n) if (vv[j] != 1 && vv[(j + 1) % n] != 1) {
                vv.insert(vv.begin() + j + 1, 1);
                break;
            }
        } else {
            REP(j, n) if (vv[j] == 0 && vv[(j + 1) % n] == 0) {
                vv.insert(vv.begin() + j + 1, 1);
                break;
            }
            t--;
        }
    }
    REP(i, c) {
        int n = vv.size();
        if (t == 0) {
            REP(j, n) if (vv[j] != 2 && vv[(j + 1) % n] != 2) {
                vv.insert(vv.begin() + j + 1, 2);
                break;
            }
        } else {
            REP(j, n) if (vv[j] == 0 && vv[(j + 1) % n] == 0) {
                vv.insert(vv.begin() + j + 1, 2);
                break;
            }
            t--;
        }
    }
    assert(vv.size() == a + b + c);
    return vv;
}

bool check() {
    if ( v > y || o > b || g > r) return false;
    s = "";
    if (v == y && v > 0) {
        if (r + b + o + g > 0) return false;
        else REP(i, v) s += "YV";
        return true;
    }
    if (o == b && o > 0) {
        if (r + y + v + g > 0) return false;
        else REP(i, o) s += "BO";
        return true;
    }
    if (g == r && g > 0) {
        if (y + b + v + o > 0) return false;
        else REP(i, g) s += "RG";
        return true;
    }
    y -= v, b -= o, r -= g;
    vector<pic> a;
    a.push_back(MP(r, 'R'));
    a.push_back(MP(y, 'Y'));
    a.push_back(MP(b, 'B'));
    sort(ALL(a)); reverse(ALL(a));
    int n = r + b + y;
    if (a[0].first > n / 2) return false;
    vector<int> vv = build(a[0].first, a[1].first, a[2].first);
    REP(i, SIZE(vv)) {
        if (a[vv[i]].second == 'Y' && v > 0) {
            REP(j, v) s += "YV";
            v = 0;
        }
        if (a[vv[i]].second == 'B' && o > 0) {
            REP(j, o) s += "BO";
            o = 0;
        }
        if (a[vv[i]].second == 'R' && g > 0) {
            REP(j, g) s += "RG";
            g = 0;
        }
        s += a[vv[i]].second;
    }
    return true;
}

void add(char c) {
    if (c == 'R') cnt[0]++;
    if (c == 'O') cnt[0]++, cnt[1]++;
    if (c == 'Y') cnt[1]++;
    if (c == 'G') cnt[1]++, cnt[2]++;
    if (c == 'B') cnt[2]++;
    if (c == 'V') cnt[2]++, cnt[0]++;
}

void solve() {
    int n;
    cin >> n >> r >> o >> y >> g >> b >> v;
    int rr = r, oo = o, yy = y, gg = g, bb = b, vv = v;
    if (!check()) cout << "IMPOSSIBLE" << endl;
    else {
        cout << s << endl;
        assert(s.size() == n);
        REP(i, n) {
            if (s[i] == 'R') rr--;
            if (s[i] == 'O') oo--;
            if (s[i] == 'Y') yy--;
            if (s[i] == 'G') gg--;
            if (s[i] == 'B') bb--;
            if (s[i] == 'V') vv--;
        }
        assert(rr == 0 && oo == 0 && yy == 0 && gg == 0 && bb == 0 && vv == 0);
        REP(i, n) {
            char c = s[i], d = s[(i + 1) % n];
            cnt[0] = cnt[1] = cnt[2] = 0;
            add(c); add(d);
            REP(j, 3) assert(cnt[j] <= 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int T; cin >> T;
    REP(i, T) {
        printf("Case #%d: ", i + 1);
        solve();
    }
    return 0;
}
