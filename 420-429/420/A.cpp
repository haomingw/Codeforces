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
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

int n, a[55][55];
map<int, bool> mp;

bool can(int x, int y) {
    mp.clear();
    int target = a[x][y];
    REP(i, n) mp[target - a[x][i]] = true;
    REP(i, n) if (mp[a[i][y]]) return true;
    return false;
}

int main() {
    scanf("%d", &n);
    REP(i, n) REP(j, n) scanf("%d", &a[i][j]);
    REP(i, n) REP(j, n) {
        if (a[i][j] == 1) continue;
        if (!can(i, j)) return !printf("No\n");
    }
    printf("Yes\n");
    return 0;
}

