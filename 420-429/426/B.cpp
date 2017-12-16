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

const int inf = 1e9 + 5;
int l[26], r[26];
set<int> entrances;

int main() {
    int n, k, index;
    cin >> n >> k;
    string s;
    cin >> s;
    REP(i, 26) l[i] = inf;
    REP(i, n) {
        index = s[i] - 'A';
        entrances.insert(index);
        l[index] = min(l[index], i);
        r[index] = max(r[index], i);
    }
    int cnt, ans = 0;
    REP(i, n) {
        cnt = 0;
        for (int e : entrances) {
            if (i >= l[e] && i <= r[e]) cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << (ans <= k ? "NO" : "YES") << endl;
    return 0;
}


