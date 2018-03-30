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

const int maxn = 55;
int n, m, a[maxn][maxn], f[maxn * 2];

int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}

bool solve() {
    REP(i, n + m) f[i] = i;
    REP(i, n) REP(j, m) if (a[i][j]) {
        f[find(i)] = find(j + n);
    }
    REP(i, n) REP(j, m)
        if ((find(i) == find(j + n)) ^ a[i][j]) return false;
    return true;
}

int main() {
    cin >> n >> m;
    string s;
    REP(i, n) {
        cin >> s;
        REP(j, m) a[i][j] = s[j] == '#';
    }
    if (solve()) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
