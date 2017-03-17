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

int a[200];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, ans = 0; cin >> n;
    string s;
    a['T'] = 4, a['C'] = 6, a['O'] = 8;
    a['D'] = 12, a['I'] = 20;
    REP(i, n) {
        cin >> s;
        ans += a[s[0]];
    }
    cout << ans << endl;
    return 0;
}
