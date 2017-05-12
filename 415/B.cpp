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
    int n, f;
    scanf("%d%d", &n, &f);
    int k, l;
    ll sold = 0;
    REP(i, n) {
        scanf("%d%d", &k, &l);
        sold += min(k, l);
        a[i] = min(2 * k, l) - min(k, l);
    }
    sort(a, a + n);
    REP(i, f) sold += a[n - 1 - i];
    cout << sold << endl;
    return 0;
}
