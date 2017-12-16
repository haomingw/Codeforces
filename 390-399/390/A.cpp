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
    int n; cin >> n;
    int a[n], cnt = 0;
    REP(i, n) scanf("%d", &a[i]);
    vector<pii> p;
    REP(i, n) if (a[i] == 0) cnt++;
    if (cnt == n) return !printf("NO\n");
    cout << "YES" << endl;
    int l = 1, r = 1;
    REP(i, n) {
        if (a[i] != 0) {
            r = i + 1;
            p.push_back(MP(l, r));
            l = r + 1;
        }
    }
    if (r != n) {
        p.back().second = n;
    }
    int ans = p.size();
    cout << ans << endl;
    REP(i, ans) cout << p[i].first << " " << p[i].second << endl;
    return 0;
}
