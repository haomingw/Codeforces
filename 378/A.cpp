#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <utility>
#include <algorithm>
#include <unordered_map>
using namespace std;

#define FOR(i,a,b) for(int i=(a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)
#define PER(i,a) for(int i = (a) - 1; i >= 0; --i)
#define SIZE(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;

bool jump(char a) {
    char c[6] = {'A', 'E', 'I', 'O', 'U', 'Y'};
    REP(i, 6) {
        if (c[i] == a) return true;
    }
    return false;
}

int main() {
    string s;
    cin >> s;
    int ans = 0, prev = -1;
    for (int i = 0; i < s.size(); i++) {
        if (jump(s[i])) {
            ans = max(i - prev, ans);
            prev = i;
        }
    }
    ans = max(ans, int(s.size() - prev));
    cout << ans << endl;
    return 0;
}
