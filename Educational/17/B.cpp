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
    int a, b, c;
    cin >> a >> b >> c;
    int m, x;
    cin >> m;
    string s;
    vector<int> p, q;
    REP(i, m) {
        cin >> x >> s;
        if (s[0] == 'U') p.push_back(x);
        else q.push_back(x);
    }
    sort(ALL(p));
    sort(ALL(q));
    int nb = 0, p1 = 0, p2 = 0;
    ll ans = 0;
    while (a-- && p1 < SIZE(p)) {
        ans += p[p1];
        p1++, nb++;
    }
    while (b-- && p2 < SIZE(q)) {
        ans += q[p2];
        p2++, nb++;
    }
    while (c--) {
        if (p1 == SIZE(p) && p2 == SIZE(q)) break;
        nb++;
        if (p1 < SIZE(p) && p2 < SIZE(q)) {
            if (p[p1] < q[p2]) ans += p[p1], p1++;
            else ans += q[p2], p2++;
        } else if (p1 < SIZE(p)) ans += p[p1], p1++;
        else ans += q[p2], p2++;
    }
    cout << nb << " " << ans << endl;
    return 0;
}
