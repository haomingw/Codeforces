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

ll sum(ll x) {
    return x * (x + 1) / 2;
}

int main() {
    int m, b;
    scanf("%d%d", &m, &b);
    ll ans = 0, x, t;
    for (int y = b; y >= 0; y--) {
        x = m * (b - y);
        t = (x + 1) * sum(y) + (y + 1) * sum(x);
        ans = max(ans, t);
    }
    cout << ans << endl;
    return 0;
}

