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

const int maxn = 105;
int a[maxn];

int main() {
    int n, m;
    cin >> n >> m;
    int l, r;
    REP(i, n) {
        cin >> l >> r;
        REPP(j, l, r + 1) a[j] = 1;
    }
    vector<int> v;
    REPP(i, 1, m + 1) if (!a[i]) v.push_back(i);
    cout << v.size() << endl;
    REP(i, SZ(v)) cout << v[i] << " "; cout << endl;
    return 0;
}
