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

const int inf = 1e5 + 5;
const int maxn = 300;
int a[maxn], b[maxn];

int main() {
    string s, t = "Bulbasaur"; cin >> s;
    int n = s.size(), ans = inf;
    REP(i, n) a[s[i]]++;
    REP(i, t.size()) b[t[i]]++;
    REP(i, maxn) if (b[i]) ans = min(ans, a[i] / b[i]);
    cout << ans << endl;
    return 0;
}
