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

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int n, x;
    scanf("%d", &n);
    int cnt = 0, ans = 0, c = 0;
    REP(i, n) {
        scanf("%d", &x);
        c = gcd(x, c);
        if (x & 1) cnt++;
        else ans += cnt / 2 + 2 * (cnt & 1), cnt = 0;
    }
    ans += cnt / 2 + 2 * (cnt & 1);
    cout << "YES" << endl;
    if (c == 1) cout << ans << endl;
    else cout << 0 << endl;
    return 0;
}
