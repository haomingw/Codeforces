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
    set<int> d, r;
    REP(i, n) {
        if (s[i] == 'D') d.insert(i);
        else r.insert(i);
    }
    int cnt = n;
    while (!d.empty() && !r.empty()) {
        int dd = *(d.begin()), rr = *(r.begin());
        if (dd < rr) {
            d.erase(dd);
            r.erase(rr);
            d.insert(cnt);
        } else {
            d.erase(dd);
            r.erase(rr);
            r.insert(cnt);
        }
        cnt++;
    }
    char ans = d.empty() ? 'R' : 'D';
    cout << ans << endl;
    return 0;
}
