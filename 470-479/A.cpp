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

int n;
string s;

bool solve() {
    REPP(i, 1, n) if (s[i] == s[i - 1] && s[i] != '?') return false;
    REP(i, n) if (s[i] == '?') {
        if (i == 0 || i == n - 1) return true;
        if (s[i + 1] == s[i - 1] || s[i - 1] == '?' || s[i + 1] == '?') return true;
    }
    return false;
}

int main() {
    cin >> n;
    cin >> s;
    if (solve()) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
