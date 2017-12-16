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

const int maxn = 1005;
int a[maxn], b[maxn];

int main() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    REP(i, n) {
        a[i] = s[i] - '0';
        b[i] = t[i] - '0';
    }
    sort(a, a + n);
    sort(b, b + n);
    int cnt = 0, p1 = 0, p2 = 0;
    while (p2 < n) {
        if (a[p1] <= b[p2]) p1++, cnt++;
        p2++;
    }
    cout << n - cnt << endl;
    p1 = p2 = cnt = 0;
    while (p2 < n) {
        if (a[p1] < b[p2]) p1++, cnt++;
        p2++;
    }
    cout << cnt << endl;
    return 0;
}
