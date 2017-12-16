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

const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
int f[maxn], rf[maxn];

inline void add(int& a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}

inline int mul(int a, int b) {
    return 1LL * a * b % mod;
}

int rev(int a) {
    int n = mod - 2;
    int res = 1;
    while (n) {
        if (n & 1) res = mul(res, a);
        a = mul(a, a);
        n >>= 1;
    }
    return res;
}

int C(int n, int k) {
    int res = f[n];
    res = mul(res, rf[k]);
    res = mul(res, rf[n - k]);
    return res;
}

int main() {
    string s; cin >> s;
    int n = s.size(), na = 0, nb = 0;
    rf[0] = f[0] = 1;
    for (int i = 1; i < n; i++) {
        f[i] = mul(i, f[i - 1]);
        rf[i] = mul(rev(i), rf[i - 1]);
    }
    REP(i, n) if (s[i] == ')') nb++;
    int ans = 0;
    REP(i, n) {
        if (s[i] == '(') na++;
        else nb--;
        if (s[i] == '(') {
            add(ans, C(na + nb - 1, na));
        }
    }
    cout << ans << endl;
    return 0;
}
