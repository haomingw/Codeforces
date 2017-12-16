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

int main() {
    int n; cin >> n;
    string s; cin >> s;
    string fi, se, mi = "", ans;
    for (int i = n - 1; i > 0; i -= 2) {
        se = s[i] + se;
        fi = fi + s[i - 1];
    }
    if (n & 1) mi = s[0];
    ans = fi + mi + se;
    cout << ans << endl;
    return 0;
}
