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

const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
int f[maxn];

int add(int a, int b) {
    a += b;
    if (a >= mod) a -= mod;
    else if (a < 0) a += mod;
    return a;
}

int powmod(int a, int b) {
    int res = 1;
    for (; b; b >>= 1) {
        if (b & 1) res = 1LL * res * a % mod;
        a = 1LL * a * a % mod;
    }
    return res;
}

void init() {
    f[0] = f[1] = 1;
    REPP(i, 2, maxn) f[i] = 1LL * f[i - 1] * i % mod;
}

int C(int n, int k) {
    if (n < k) return 0;
    return 1LL * f[n] * powmod(f[k], mod - 2) % mod * powmod(f[n - k], mod - 2) % mod;
}

int solve(vector<int>& a) {
    int n = a.size();
    if (n == 1) return a[0];
    if (n & 1) {
        vector<int> b;
        REP(i, n - 1) {
            if (i & 1) b.push_back(add(a[i], -a[i + 1]));
            else b.push_back(add(a[i], a[i + 1]));
        }
        return solve(b);
    }
    int x = 0, y = 0;
    REP(i, n) {
        if (i % 2 == 0) x = add(x, 1LL * a[i] * C(n / 2 - 1, i / 2) % mod);
        else y = add(y, 1LL * a[i] * C(n / 2 - 1, i / 2) % mod);
    }
    if (n / 2 % 2 == 0) return add(x, -y);
    else return add(x, y);
}


int main() {
    int n, x;
    scanf("%d", &n);
    vector<int> v;
    REP(i, n) {
        scanf("%d", &x);
        v.push_back(x);
    }
    init();
    cout << solve(v) << endl;
    return 0;
}
