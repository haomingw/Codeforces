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

int n, a[15];

bool solve() {
    int m = 1 << n;
    int sum = 0, x, y;
    REP(i, n) sum += a[i];
    REP(i, m) {
        x = 0;
        REP(j, n) if (i & (1 << j)) x += a[j];
        y = sum - x;
        if (abs(x - y) % 360 == 0) return true;
    }
    return false;
}

int main() {
    cin >> n;
    REP(i, n) cin >> a[i];
    cout << (solve() ? "YES" : "NO") << endl;
    return 0;
}
