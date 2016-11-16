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
    int n;
    cin >> n;
    int a[n], b[n], c[n], d[n];
    ll sum = 0;
    REP(i, n) cin >> b[i];
    REP(i, n) cin >> c[i];
    REP(i, n) {
        d[i] = b[i] + c[i];
        sum += d[i];
    }
    sum /= (2 * n);
    REP(i, n) a[i] = (d[i] - sum) / n;

    int b1[n], c1[n], bits[n][31], kbits[31];
    REP(i, n) if (a[i] < 0) return !printf("-1\n");
    REP(i, n) REP(j, 31) {
        if ((a[i] & (1 << j)) == 0) bits[i][j] = 0;
        else bits[i][j] = 1;
    }
    REP(i, 31) {
        kbits[i] = 0;
        REP(j, n) kbits[i] += bits[j][i];
    }
    fill(b1, b1 + n, 0);
    fill(c1, c1 + n, 0);
    REP(i, n) REP(j, 31) {
        int bb = bits[i][j] ? kbits[j] : 0;
        b1[i] += bb << j;
        int cc = bits[i][j] ? n : kbits[j];
        c1[i] += cc << j;
    }
    REP(i, n) {
        if (b1[i] != b[i] || c1[i] != c[i]) return !printf("-1\n");
    }
    REP(i, n) cout << a[i] << " "; cout << endl;
    return 0;
}
