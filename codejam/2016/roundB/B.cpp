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
using namespace std;

#define REPP(i,a,b) for(int i=(a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)
#define PER(i,a) for(int i = (a) - 1; i >= 0; --i)
#define SIZE(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

const ll inf = 1LL << 60;
ll ansA, ansB;

ll parse(string s) {
    ll a = 0;
    REP(i, SIZE(s)) a = a * 10 + s[i] - '0';
    return a;
}

string str(ll x, int n) {
    string s;
    REP(i, n) {
        char c = '0' + x % 10;
        s = c + s;
        x /= 10;
    }
    return s;
}

void update(ll a, ll b) {
    if (abs(a - b) < abs(ansA - ansB)) {
        ansA = a, ansB = b;
    } else if (abs(a - b) == abs(ansA - ansB)) {
        ansA = min(ansA, a);
        ansB = min(ansB, b);
    }
}

void check(string s1, string s2, int k, int p, int q, int r, int s) {
    int n = s1.size();
    string sa = s1, sb = s2;
    REP(i, k) {
        char c = '0';
        if (s1[i] != '?') c = s1[i];
        if (s2[i] != '?') c = s2[i];
        if (sa[i] == '?') sa[i] = c;
        if (sb[i] == '?') sb[i] = c;
    }
    if (k < n) {
        if (sa[k] == '?') sa[k] = '0' + p;
        if (sb[k] == '?') sb[k] = '0' + q;
    }
    string t = "09";
    REPP(i, k + 1, n) {
        if (sa[i] == '?') sa[i] = t[r];
        if (sb[i] == '?') sb[i] = t[s];
    }
    update(parse(sa), parse(sb));
}

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    ansA = inf, ansB = 0;
    REP(i, n + 1) REP(p, 10) REP(q, 10) REP(r, 2) REP(s, 2)
        check(s1, s2, i, p, q, r, s);
    cout << str(ansA, n) << " " << str(ansB, n) << endl;
}

int main() {
    int T; cin >> T;
    REP(i, T) {
        printf("Case #%d: ", i + 1);
        solve();
    }
    return 0;
}
