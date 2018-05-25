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

int main() {
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0, cnt = 0;
    REP(i, n) {
        if (s[i] == 'x') cnt++;
        else {
            ans += max(cnt - 2, 0);
            cnt = 0;
        }
    }
    ans += max(cnt - 2, 0);
    cout << ans << endl;
    return 0;
}
