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

const int N = 100;

int main() {
    ll n;
    cin >> n;
    ll a[N];
    a[0] = 2;
    a[1] = 3;
    REPP (i, 2, N) a[i] = a[i - 1] + a[i - 2];
    int ans = upper_bound(a, a + N, n) - a;
    cout << ans << endl;
    return 0;
}
