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
string a[maxn][2];
int mark[maxn];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    string s, t;
    map<string, int> m;
    REP(i, n) {
        cin >> s >> t;
        a[i][0] = s.substr(0, 3);
        a[i][1] = s.substr(0, 2) + t[0];
        m[a[i][0]]++;
    }
    while (true) {
        bool same = false;
        REP(i, n) if (!mark[i] && m[a[i][0]] > 1) {
            mark[i] = 1;
            m[a[i][1]]++;
            same = true;
        }
        if (!same) break;
    }
    m.clear();
    REP(i, n) if (mark[i]) {
        if (!m.count(a[i][1])) m[a[i][1]] = 1;
        else return !printf("NO\n");
    }
    cout << "YES" << endl;
    REP(i, n) cout << a[i][mark[i]] << endl;
    return 0;
}
