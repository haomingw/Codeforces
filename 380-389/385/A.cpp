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
    string s;
    cin >> s;
    int n = SIZE(s), ans = 0;
    unordered_map<string, int> hmap;
    REP(i, n) {
        s = s[n - 1] + s.substr(0, n - 1);
        if (hmap[s] > 0) break;
        else {
            hmap[s] += 1;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
