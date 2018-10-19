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

const int maxn = 1e5 + 5;
int a[maxn];

bool solve() {
    int n;
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    int p = 0;
    while (p < n - 1 && a[p] <= a[p + 1]) p++;
    if (p == n - 1) return true;
    p++;
    REP(i, n - 1) {
        if (a[(p + i) % n] > a[(p + i + 1) % n])
            return false;
    }
    return true;
}

int main() {
    int T; cin >> T;
    REP(i, T) {
        cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}
