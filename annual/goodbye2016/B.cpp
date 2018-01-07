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
    int n, t; cin >> n;
    string s;
    int c = 0;
    REP(i, n) {
        cin >> t >> s;
        if ((c == 0 && s[0] != 'S') || (c == 20000 && s[0] != 'N'))
            return !printf("NO\n");
        if (s[0] == 'N') c -= t;
        else if (s[0] == 'S') c += t;
        if (c < 0 || c > 20000) return !printf("NO\n");
    }
    if (c == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
