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

bool isTidy(ll a) {
    string s = to_string(a);
    int n = s.size(), p = -1;
    REP(i, n - 1) {
        if (s[i] > s[i + 1]) {
            p = i; break;
        }
    }
    return p == -1;
}

int solve() {
    ll a;
    cin >> a;
    if (isTidy(a)) return !printf("%lld\n", a);
    ll base = 1;
    while (true) {
        int x = a / base % 10;
        a += base * (9 - x);
        base *= 10;
        a -= base;
        if (isTidy(a)) return !printf("%lld\n", a);
    }
    cerr << "not found" << endl;
    return 0;
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
