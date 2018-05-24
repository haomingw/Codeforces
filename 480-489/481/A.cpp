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

const int maxn = 1005;
int a[55];
bool used[maxn];

int main() {
    int n; cin >> n;
    REP(i, n) cin >> a[i];
    vector<int> v;
    PER(i, n) if (!used[a[i]]) {
        v.push_back(a[i]);
        used[a[i]] = true;
    }
    reverse(ALL(v));
    n = v.size();
    cout << n << endl;
    REP(i, n) cout << v[i] << " "; cout << endl;
    return 0;
}
