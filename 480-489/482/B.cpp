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

const int maxn = 256;
int n, a[maxn], b[maxn], c[maxn], ma, mb, mc;
string p, q, r;

int main() {
    cin >> n >> p >> q >> r;
    int m = p.size();
    REP(i, m) ma = max(ma, ++a[p[i]]);
    REP(i, m) mb = max(mb, ++b[q[i]]);
    REP(i, m) mc = max(mc, ++c[r[i]]);
    if (n == 1 && ma == m) ma = m - 1;
    else ma = min(ma + n, m);
    if (n == 1 && mb == m) mb = m - 1;
    else mb = min(mb + n, m);
    if (n == 1 && mc == m) mc = m - 1;
    else mc = min(mc + n, m);
    if (ma > mb && ma > mc) cout << "Kuro" << endl;
    else if (mb > ma && mb > mc) cout << "Shiro" << endl;
    else if (mc > ma && mc > mb) cout << "Katie" << endl;
    else cout << "Draw" << endl;
    return 0;
}
