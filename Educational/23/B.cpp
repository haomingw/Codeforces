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
#include <cassert>
using namespace std;

#define REPP(i,a,b) for(int i=(a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)
#define PER(i,a) for(int i = (a) - 1; i >= 0; --i)
#define SIZE(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 1e5 + 5;
int a[maxn];

int main() {
    int n, c = 0, b = 0;
    scanf("%d", &n);
    REP(i, n) scanf("%d", &a[i]);
    sort(a, a + n);
    REP(i, n) {
        if (a[i] < a[2]) c++;
        else if (a[i] == a[2]) b++;
        else break;
    }
    c = 3 - c;
    ll ans;
    if (c == 1) ans = b;
    else if (c == 2) ans = 1LL * b * (b - 1) / 2;
    else ans = 1LL * b * (b - 1) * (b - 2) / 6;
    cout << ans << endl;
    return 0;
}
