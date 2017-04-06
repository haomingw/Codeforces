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

const int maxn = 2e5 + 5;
int a[maxn];

int main() {
    int n;
    scanf("%d", &n);
    REP(i, n) scanf("%d", &a[i]);
    sort(a, a + n);
    int cnt = 0, x = 2e9;
    REP(i, n - 1) {
        int d = a[i + 1] - a[i];
        if (x > d) x = d, cnt = 1;
        else if (x == d) cnt++;
    }
    cout << x << " " << cnt << endl;
    return 0;
}
