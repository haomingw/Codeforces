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

vector<int> solve(string &a, string &b) {
    int n = a.size();
    vector<int> res;
    REP(i, n) if (a[i] != b[i]) res.push_back(i + 1);
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    string s, t, tmp;
    cin >> s >> t;
    vector<int> ans(1005);
    REP(i, m - n + 1) {
        tmp = t.substr(i, n);
        vector<int> res = solve(tmp, s);
        if (SZ(res) < SZ(ans)) ans = res;
    }
    cout << ans.size() << endl;
    for (int x : ans) cout << x << " "; cout << endl;
    return 0;
}
