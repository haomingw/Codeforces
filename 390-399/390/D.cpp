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

const int maxn = 3e5 + 5;

struct Coupon {
    int l, r, id;

    Coupon(int l, int r, int id): l(l), r(r), id(id) {}
};

bool operator < (const Coupon& a, const Coupon& b) {
    return a.l < b.l;
}

int main() {
    int n, k, l, r;
    scanf("%d%d", &n, &k);;
    vector<Coupon> p;
    REP(i, n) {
        scanf("%d%d", &l, &r);
        p.push_back(Coupon(l, r, i + 1));
    }
    sort(ALL(p));
    int ans = 0, ind = n - 1;
    set<pii> q;
    REP(i, n) {
        int lp = p[i].l, rp = p[i].r, id = p[i].id;
        q.insert(MP(rp, id));
        while (q.size() > k) q.erase(q.begin());
        if (q.size() == k) {
            int d = q.begin()->first - lp + 1;
            if (d > ans) ans = d, ind = i;
        }
    }
    cout << ans << endl;
    q.clear();
    REP(i, n) {
        int lp = p[i].l, rp = p[i].r, id = p[i].id;
        q.insert(MP(rp, id));
        while (q.size() > k) q.erase(q.begin());
        if (i == ind) {
            for (pii x : q) cout << x.second << " "; cout << endl;
            break;
        }
    }
    return 0;
}
