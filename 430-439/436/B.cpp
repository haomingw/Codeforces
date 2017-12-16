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

bool isLower(char c) {
    return c >= 'a' && c <= 'z';
}

int main() {
    int n; cin >> n;
    string s; cin >> s;
    int p = 0, ans = 0;
    set<char> st;
    while (p < n) {
        while (p < n && !isLower(s[p])) p++;
        st.clear();
        while (p < n && isLower(s[p])) st.insert(s[p++]);
        ans = max(SZ(st), ans);
    }
    cout << ans << endl;
    return 0;
}
