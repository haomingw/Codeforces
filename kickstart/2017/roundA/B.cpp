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

char s[8005], t[8005], buf[2005];
bool dp[8005][8005];

int read(char* p) {
    int sz = 0;
    scanf("%s", buf);
    for (int i = 0; buf[i]; i++) {
        if (buf[i] != '*') *(p++) = buf[i], sz++;
        else {
            REP(j, 4) *(p++) = '*';
            sz += 4;
        }
    }
    *p = '\0';
    return sz;
}

bool solve() {
    int n = read(s), m = read(t);
    REP(i, n + 1) REP(j, m + 1) dp[i][j] = false;
    dp[0][0] = true;
    REP(i, n + 1) REP(j, m + 1) {
        if (dp[i][j]) {
            if (s[i] == t[j] || s[i] == '*' || t[j] == '*') dp[i + 1][j + 1] = true;
            if (s[i] == '*') dp[i + 1][j] = true;
            if (t[j] == '*') dp[i][j + 1] = true;
        }
    }
    return dp[n][m];
}

int main() {
    int T; cin >> T;
    REP(i, T) {
        printf("Case #%d: ", i + 1);
        if (solve()) cout << "TRUE" << endl;
        else cout << "FALSE" << endl;
    }
    return 0;
}
