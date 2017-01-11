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

const int maxn = 30;

void solve() {
    string s, l; cin >> s;
    int a[maxn], ans[maxn], n = s.size();
    memset(a, 0, sizeof(a));
    REP(i, n) a[s[i] - 'A']++;
    ans[0] = a['Z' - 'A']; l = "ZERO";
    REP(i, SIZE(l)) a[l[i] - 'A'] -= ans[0];
    ans[2] = a['W' - 'A']; l = "TWO";
    REP(i, SIZE(l)) a[l[i] - 'A'] -= ans[2];
    ans[4] = a['U' - 'A']; l = "FOUR";
    REP(i, SIZE(l)) a[l[i] - 'A'] -= ans[4];
    ans[6] = a['X' - 'A']; l = "SIX";
    REP(i, SIZE(l)) a[l[i] - 'A'] -= ans[6];
    ans[8] = a['G' - 'A']; l = "EIGHT";
    REP(i, SIZE(l)) a[l[i] - 'A'] -= ans[8];

    ans[7] = a['S' - 'A']; l = "SEVEN";
    REP(i, SIZE(l)) a[l[i] - 'A'] -= ans[7];
    ans[5] = a['F' - 'A']; l = "FIVE";
    REP(i, SIZE(l)) a[l[i] - 'A'] -= ans[5];
    ans[3] = a['R' - 'A']; l = "THREE";
    REP(i, SIZE(l)) a[l[i] - 'A'] -= ans[3];
    ans[9] = a['I' - 'A']; l = "NINE";
    REP(i, SIZE(l)) a[l[i] - 'A'] -= ans[9];
    ans[1] = a['O' - 'A']; l = "ONE";
    REP(i, SIZE(l)) a[l[i] - 'A'] -= ans[1];

    REP(i, 10) REP(j, ans[i]) cout << i;
    cout << endl;
}

int main() {
    int T; cin >> T;
    REP(i, T) {
        printf("Case #%d: ", i + 1);
        solve();
    }
    return 0;
}
