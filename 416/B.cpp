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

const int maxn = 1e4 + 5;
int p[maxn];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    REP(i, n) scanf("%d", &p[i]);
    int l, r, x, cnt;
    REP(i, m) {
        scanf("%d%d%d", &l, &r, &x);
        l--, r--, x--;
        cnt = 0;
        REPP(j, l, r + 1) if (p[j] < p[x]) cnt++;
        if (cnt == x - l) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
