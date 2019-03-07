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
#define REPP(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)
#define PER(i,a) for(int i = (a) - 1; i >= 0; --i)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int mod = 1e9 + 7;
int n, a[55][55];
ll k;

void add(int& x, int y) {
    x += y;
    if (x >= mod) x -= mod;
}

int mul(int x, int y) {
    return 1LL * x * y % mod;
}

struct Matrix {
    vector<vector<int> > v;
    Matrix() {
        v.resize(n, vector<int>(n));
    }
    Matrix operator * (const Matrix& b) const {
        Matrix c = Matrix();
        REP(i, n) REP(j, n) REP(k, n) {
            add(c.v[i][j], mul(v[i][k], b.v[k][j]));
        }
        return c;
    }
};


int main() {
    cin >> n >> k;
    REP(i, n) REP(j, n) cin >> a[i][j];
    Matrix m = Matrix(), base = Matrix();
    REP(i, n) m.v[i][i] = 1;
    REP(i, n) REP(j, n) base.v[i][j] = a[i][j];
    while (k) {
        if (k & 1) {
            m = m * base;
        }
        base = base * base;
        k /= 2;
    }
    int ans = 0;
    REP(i, n) REP(j, n) add(ans, m.v[i][j]);
    cout << ans << endl;
    return 0;
}
