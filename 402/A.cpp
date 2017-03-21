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

int a[6], b[6], c[6];

int main() {
    int n, x; cin >> n;
    REP(i, n) {
        scanf("%d", &x);
        a[x]++, c[x]++;
    }
    REP(i, n) {
        scanf("%d", &x);
        b[x]++, c[x]++;
    }
    x = 0;
    REPP(i, 1, 6) {
        if (c[i] & 1) return !printf("-1\n");
        x += abs(a[i] - c[i] / 2);
    }
    cout << x / 2 << endl;
    return 0;
}
