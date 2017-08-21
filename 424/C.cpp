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

const int maxn = 2005;
int n, k, a[maxn], b[maxn], c[maxn], d[maxn];
map<int, bool> mp;

bool check(int init) {
    mp.clear();
    REP(i, k) mp[init + c[i + 1]] = true;
    REP(i, n) if (!mp.count(b[i])) return false;
    return true;
}

int main() {
    scanf("%d%d", &k, &n);
    REP(i, k) scanf("%d", &a[i]);
    REP(i, n) scanf("%d", &b[i]);
    REP(i, k) c[i + 1] = c[i] + a[i];
    set<int> ans;
    REP(i, k) {
        int init = b[0] - c[i + 1];
        if (check(init)) ans.insert(init);
    }
    cout << ans.size() << endl;
    return 0;
}


