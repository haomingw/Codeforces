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
#define SIZE(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    string s, t = "";
    cin >> s;
    int n = s.size();
    if (n & 1) {
        cout << "AMBIGUOUS" << endl;
        return;
    }
    REP(i, n) t += "*";
    int sum, prev = 0;
    for (int i = 0; i < n; i += 2) {
        sum = s[i] - 'A';
        prev = (sum - prev + 26) % 26;
        t[i + 1] = char(prev + 'A');
    }
    prev = 0;
    for (int i = n - 1; i >= 0; i -= 2) {
        sum = s[i] - 'A';
        prev = (sum - prev + 26) % 26;
        t[i - 1] = char(prev + 'A');
    }
    cout << t << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int T; cin >> T;
    REP(i, T) {
        printf("Case #%d: ", i + 1);
        solve();
    }
    return 0;
}
