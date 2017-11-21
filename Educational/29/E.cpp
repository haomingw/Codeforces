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

const int maxn = 2e5 + 5;
int l[maxn], r[maxn];

int main() {
    int n;
    scanf("%d", &n);
    vector<int> v;
    REP(i, n) {
        scanf("%d%d", l + i, r + i);
        l[i]--;
        v.push_back(l[i]);
        v.push_back(r[i]);
    }
    sort(ALL(v));
    v.resize(unique(ALL(v)) - v.begin());
    int x = v.size();
    vector<int> add(x + 1);
    REP(i, n) {
        l[i] = lower_bound(ALL(v), l[i]) - v.begin();
        r[i] = lower_bound(ALL(v), r[i]) - v.begin();
        add[l[i]]++, add[r[i]]--;
    }
    REP(i, x) add[i + 1] += add[i];
    vector<int> sum(x + 1);
    REP(i, x) sum[i + 1] = sum[i] + (add[i] >= 2);
    REP(i, n) {
        if (r[i] - l[i] == sum[r[i]] - sum[l[i]]) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
