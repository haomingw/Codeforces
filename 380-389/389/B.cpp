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
typedef pair<char, char> pcc;

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), h[30];
    fill(h, h + 30, -1);
    vector<pcc> ans;
    REP(i, n) {
        int a = s[i] - 'a', b = t[i] - 'a';
        if (h[a] < 0 && h[b] < 0) {
            h[a] = b; h[b] = a;
            if (a != b) ans.push_back(MP(s[i], t[i]));
        } else if (h[a] != b) return !printf("-1\n");
    }
    cout << ans.size() << endl;
    REP(i, SIZE(ans)) cout << ans[i].first << " " << ans[i].second << endl;
    return 0;
}
