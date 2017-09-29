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

int main() {
    int a, b, f, k;
    cin >> a >> b >> f >> k;
    int go = 0, d[2], ans = 0;
    d[0] = f, d[1] = a - f;
    int now = b;
    REP(i, k + 1) {
        int need = 2 * d[go];
        if (i == 0 || i == k) need >>= 1;
        if (b < need) return !printf("-1\n");
        if (now >= need) now -= need;
        else now = b - need, ans++;
        go ^= 1;
    }
    cout << ans << endl;
    return 0;
}
