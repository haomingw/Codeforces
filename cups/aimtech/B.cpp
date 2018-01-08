#include <iostream>
#include <cstdio>
#include <cmath>
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
    int n, a;
    cin >> n >> a;
    int x[n];
    REP(i, n) cin >> x[i];
    sort(x, x + n);
    if (n == 1) return !printf("0\n");
    int d1 = min(abs(a - x[0]), abs(x[n - 2] - a)) + x[n - 2] - x[0],
        d2 = min(abs(a - x[1]), abs(x[n - 1] - a)) + x[n - 1] - x[1];
    cout << min(d1, d2) << endl;
    return 0;
}
