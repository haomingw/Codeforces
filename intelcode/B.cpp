#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define REP(i, a, b) for (int i = a; i < b; ++i)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()

int n, m, p[30][30];
bool check() {
    int cnt;
    REP(i, 0, n) {
        cnt = 0;
        REP(j, 0, m) cnt += p[i][j] != j + 1;
        if (cnt > 2) return false;
    }
    return true;
}

int main() {
    cin >> n >> m;
    REP(i, 0, n) REP(j, 0, m) scanf("%d", &p[i][j]);

    REP(a, 0, m) REP(b, a, m) {
        REP(i, 0, n) swap(p[i][a], p[i][b]);
        if (check()) return !printf("YES\n");
        REP(i, 0, n) swap(p[i][a], p[i][b]);
    }
    cout << "NO" << endl;
    return 0;
}
