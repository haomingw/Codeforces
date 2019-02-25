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
#define REPP(i,a,b) for(int i = (a); i < (b); ++i)
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
    int n;
    cin >> n;
    REP(i, n) cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; i += 2) {
        cout << a[i] << " ";
    }
    int m = n & 1 ? n - 2 : n - 1;
    for (int i = m; i >= 0; i -= 2) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
