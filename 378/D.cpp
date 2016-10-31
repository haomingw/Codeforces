#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <map>
using namespace std;

#define FOR(i,a,b) for(int i=(a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)
#define PER(i,a) for(int i = (a) - 1; i >= 0; --i)
#define SIZE(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int inf = 2e9 + 10;
const int maxn = 1e6 + 10;

int id;
set<pii> sp[maxn];
map<pii, int> hmap;
pii p[maxn];

int f(int a, int b, int c) {
    return min(a, min(b, c));
}

int hashcode(pii x) {
    if (x.first > x.second) swap(x.first, x.second);
    if (hmap.count(x) > 0) return hmap[x];
    p[id] = x;
    return hmap[x] = id++;
}

int main() {
    int n;
    cin >> n;
    int x, y, z, r = 0;
    vector<int> ans;
    REP(i, n) {
        scanf("%d %d %d", &x, &y, &z);
        if (f(x, y, z) > r) {
            r = f(x, y, z);
            ans.clear();
            ans.push_back(i + 1);
        }
        sp[hashcode(MP(x, y))].insert(MP(z, i + 1));
        sp[hashcode(MP(x, z))].insert(MP(y, i + 1));
        sp[hashcode(MP(y, z))].insert(MP(x, i + 1));
    }

    REP(i, id) {
        if (SIZE(sp[i]) > 1) {
            set<pii>::iterator it = sp[i].end(); it--;
            pii c = *it; it--;
            pii d = *it;
            if (f(p[i].first, p[i].second, c.first + d.first) > r) {
                r = f(p[i].first, p[i].second, c.first + d.first);
                ans.clear();
                ans.push_back(c.second);
                ans.push_back(d.second);
            }
        }
    }
    cout << SIZE(ans) << endl;
    REP(i, SIZE(ans)) cout << ans[i] << " ";
    return 0;
}
