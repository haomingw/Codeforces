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

const int maxn = 2e5 + 5;
int p[maxn], a[maxn], b[maxn];
set<pii> store[4];

int main() {
    int n;
    scanf("%d", &n);
    REP(i, n) scanf("%d", &p[i]);
    REP(i, n) {
        scanf("%d", &a[i]);
        store[a[i]].insert(MP(p[i], i));
    }
    REP(i, n) {
        scanf("%d", &b[i]);
        store[b[i]].insert(MP(p[i], i));
    }
    int m, c;
    scanf("%d", &m);
    REP(i, m) {
        scanf("%d", &c);
        if (store[c].empty()) cout << -1 << " ";
        else {
            int x = store[c].begin()->first, y = store[c].begin()->second;
            cout << x << " ";
            store[a[y]].erase(MP(x, y));
            store[b[y]].erase(MP(x, y));
        }
    }
    return 0;
}
