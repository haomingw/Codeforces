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

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int a[n], odd = 0, even = 0;
    vector<pii> va;
    unordered_map<int, int> hmap;
    REP(i, n) {
        scanf("%d", &a[i]);
        if (a[i] & 1) odd++;
        else even++;
        if (hmap[a[i]] > 0) va.push_back(MP(a[i], i));
        hmap[a[i]]++;
    }
    int p1 = 1, p2 = 2, ans = SIZE(va);
    for (pii v : va) {
        int val = v.first, ind = v.second;
        clog << val << " " << ind << endl;
        if (val & 1) {
            if (odd > even) {
                while (hmap[p2] > 0 && p2 <= m) p2 += 2;
                if (p2 > m) return !printf("-1\n");
                a[ind] = p2; p2 += 2;
                odd--, even++;
            } else {
                while (hmap[p1] > 0 && p1 <= m) p1 += 2;
                if (p1 > m) return !printf("-1\n");
                a[ind] = p1; p1 += 2;
            }
        } else { // even number
            if (even > odd) {
                while (hmap[p1] > 0 && p1 <= m) p1 += 2;
                if (p1 > m) return !printf("-1\n");
                a[ind] = p1; p1 += 2;
                even--, odd++;
            } else {
                while (hmap[p2] > 0 && p2 <= m) p2 += 2;
                if (p2 > m) return !printf("-1\n");
                a[ind] = p2; p2 += 2;
            }
        }
    }
    vector<int> ind1, ind2;
    REP(i, n)
        if (a[i] & 1) ind1.push_back(i);
        else ind2.push_back(i);
    int nb = abs(odd - even) / 2, id;
    ans += nb;
    if (odd > even) {
        REP(i, nb) {
            id = ind1[i];
            while (hmap[p2] > 0 && p2 <= m) p2 += 2;
            if (p2 > m) return !printf("-1\n");
            a[id] = p2; p2 += 2;
        }
    } else {
        REP(i, nb) {
            id = ind2[i];
            while (hmap[p1] > 0 && p1 <= m) p1 += 2;
            if (p1 > m) return !printf("-1\n");
            a[id] = p1; p1 += 2;
        }
    }
    cout << ans << endl;
    REP(i, n) cout << a[i] << " "; cout << endl;
    return 0;
}
