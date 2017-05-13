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

const int mod = 1e9 + 7;
const int maxn = 3e5 + 5;
int x[maxn];

int powmod(int a, int b) {
    int res = 1;
    for (; b; b >>= 1) {
        if (b & 1) res = 1LL * res * a % mod;
        a = 1LL * a * a % mod;
    }
    return res;
}

inline int mul(int a, int b) {
    return 1LL * a * b % mod;
}

inline void add(int& a, int b) {
    a += b;
    if (a >= mod) a-= mod;
    if (a < 0) a += mod;
}

int main() {
    int n;
    scanf("%d", &n);
    REP(i, n) scanf("%d", x + i);
    sort(x, x + n);
    int ans = 0, left, right;
    REP(i, n) {
        left = mul(powmod(2, i) - 1, x[i]);
        right = mul(powmod(2, n - 1 - i) - 1, x[i]);
        add(ans, left - right);
    }
    cout << ans << endl;
    return 0;
}
