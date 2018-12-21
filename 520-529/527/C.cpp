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

const int maxn = 105;
vector<string> a[maxn];
bool used[maxn * 2];

int main() {
    int n;
    cin >> n;
    int m = 2 * n - 2;
    string s;
    vector<string> v;
    REP(i, m) {
        cin >> s;
        v.push_back(s);
        a[SZ(s)].push_back(s);
    }
    REP(j, 2) {
        s = a[n - 1][j] + a[n - 1][j ^ 1][n - 2];
        bool ok = true;
        REP(i, m) if (v[i] != s.substr(0, v[i].size()) && v[i] != s.substr(n - v[i].size())) {
            ok = false;
            break;
        }
        if (!ok) continue;
        REP(i, m) if (v[i] == s.substr(0, v[i].size()) && !used[v[i].size()]) {
            cout << "P";
            used[v[i].size()] = true;
        } else {
            cout << "S";
        }
        cout << endl;
        break;
    }
    return 0;
}