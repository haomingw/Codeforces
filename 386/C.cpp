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

int main() {
    int s, x1, x2, t1, t2, p, d;
    cin >> s >> x1 >> x2;
    cin >> t1 >> t2 >> p >> d;
    if (x1 > x2) {
        x1 = s - x1;
        x2 = s - x2;
        d *= -1;
        p = s - p;
    }
    int ans = (x2 - x1) * t2, tt;
    if (d == 1) {
        if (p <= x1) tt = (x2 - p) * t1;
        else tt = (s - p + s + x2) * t1;
    } else {
        tt = (p + x2) * t1;
    }
    ans = min(ans, tt);
    cout << ans << endl;
    return 0;
}
