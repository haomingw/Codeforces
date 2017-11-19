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

int ma[4][4], mb[4][4];
ll ca, cb;

void update(int& a, int& b) {
    int ta = a, tb = b;
    if (min(ta, tb) == 1 && max(ta, tb) == 3)
        swap(ta, tb);
    if (ta > tb) ca++;
    else if (ta < tb) cb++;
    ta = ma[a][b], tb = mb[a][b];
    a = ta, b = tb;
}

int main() {
    ll k;
    int a, b;
    scanf("%lld%d%d", &k, &a, &b);
    REP(i, 3) REP(j, 3) scanf("%d", &ma[i + 1][j + 1]);
    REP(i, 3) REP(j, 3) scanf("%d", &mb[i + 1][j + 1]);
    int x = 0;
    map<pii, int> mp;
    int cycle = 1;
    while (x < k) {
        pii p = MP(a, b);
        if (mp.count(p)) {
            cycle = x - mp[p];
            break;
        };
        mp[p] = x;
        update(a, b);
        x++;
    }
    k -= x;
    if (k >= cycle) {
        int ta = ca, tb = cb;
        REP(i, cycle) update(a, b);
        k -= cycle;
        ca += (ca - ta) * (k / cycle);
        cb += (cb - tb) * (k / cycle);
    }
    k %= cycle;
    REP(i, k) update(a, b);
    cout << ca << " " << cb << endl;
    return 0;
}


