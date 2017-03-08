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

int add(int a, int b) {
    a += b;
    if (a >= mod) a -= mod;
    return a;
}

int mul(int a, int b) {
    return 1LL * a * b % mod;
}

void solve() {
    int r, c;
    cin >> r >> c;
    if (r > c) swap(r, c);
    int v1 = mul(r, c), v2 = add(r, c), v3 = 1;
    int x1 = r, x2 = r + 1, x3 = 2 * r + 1;
    if (x1 % 2 == 0) x1 /= 2; else x2 /= 2;
    int s1 = mul(x1, x2);
    if (x1 % 3 == 0) x1 /= 3; else if (x2 % 3 == 0) x2 /= 3; else x3 /= 3;
    int s2 = mul(mul(x1, x2), x3), s3 = mul(s1, s1);
    int m1 = mul(s1, v1), m2 = mul(s2, v2), m3 = mul(s3, v3);
    int ans = add(add(m1, mod - m2), m3);
    cout << ans << endl;
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
