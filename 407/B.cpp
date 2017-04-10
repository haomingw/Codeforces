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

const int maxn = 1e5 + 5;
int a[maxn];

int main() {
    ll b;
    int q, l, m;
    scanf("%lld%d%d%d", &b, &q, &l, &m);
    map<int, int> mp;
    int x;
    REP(i, m) {
        scanf("%d", &x);
        mp[x] = 1;
    }
    if (abs(b) > l) return !printf("0\n");
    int ans = 0;
    if (q == 1) {
        if (mp.count(b)) cout << 0 << endl;
        else cout << "inf" << endl;
    } else if (q == -1) {
        if (mp.count(b) && mp.count(-b)) cout << 0 << endl;
        else cout << "inf" << endl;
    } else if (q == 0) {
        if (mp.count(0)) cout << !mp.count(b) << endl;
        else cout << "inf" << endl;
    } else {
        if (b == 0) {
            if (mp.count(0)) cout << 0 << endl;
            else cout << "inf" << endl;
        } else {
            while (abs(b) <= l) {
                if (!mp.count(b)) ans++;
                b *= q;
            }
            cout << ans << endl;
        }
    }
    return 0;
}
