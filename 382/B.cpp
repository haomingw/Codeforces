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
    int n, n1, n2;
    cin >> n >> n1 >> n2;
    int a[n];
    REP(i, n) scanf("%d", &a[i]);
    sort(a, a + n);
    // REP(i, n) clog << a[i] << " "; clog << endl;
    if (n1 < n2) swap(n1, n2);
    ll sum1 = 0, sum2 = 0;
    for(int i = n - n1 - n2; i < n - n2; i++) {
        sum1 += a[i];
    }
    for(int i = n - n2; i < n; i++) {
        sum2 += a[i];
    }
    double ans = sum1 / double(n1) + sum2 / double(n2);
    printf("%.7f\n", ans);
    return 0;
}
