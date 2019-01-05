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
#define REPP(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)
#define PER(i,a) for(int i = (a) - 1; i >= 0; --i)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

string s, t[5];

bool solve() {
    REP(i, 5) {
        if (t[i][0] == s[0] || t[i][1] == s[1])
            return true;
    }
    return false;
}

int main() {
    cin >> s;
    REP(i, 5) cin >> t[i];
    cout << (solve() ? "YES" : "NO") << endl;
    return 0;
}
