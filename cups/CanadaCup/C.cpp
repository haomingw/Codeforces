#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>
using namespace std;

#define FOR(i,a,b) for(int i=(a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)
#define SIZE(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()

typedef pair<int, int> pii;
typedef long long ll;

int main() {
    string s, sa, sb;
    cin >> s;
    int p[30], tmp;
    fill(p, p + 30, -1);
    vector<int> pos;
    int len = 27;
    REP(i, len) {
        tmp = s[i] - 'A';
        if (p[tmp] < 0) p[tmp] = i;
        else {
            pos.push_back(p[tmp]);
            pos.push_back(i);
            break;
        }
    }
    int a = pos[0], b = pos[1];
    int diff = b - a;
    if (diff == 1) return !printf("Impossible\n");
    string ss = s + s;
    string st = ss.substr(b + 1, 26 - diff);
    if (diff % 2 == 0) {
        sa = st.substr(13 - diff / 2, 13 - diff / 2) + s.substr(a, diff / 2);
        sb = s.substr(a + diff / 2, diff / 2) + st.substr(0, 13 - diff / 2);
    } else {
        sa = st.substr(13 - diff / 2, 13 - diff / 2 - 1) + s.substr(a, diff / 2 + 1);
        sb = s.substr(a + diff / 2 + 1, diff / 2) + st.substr(0, 13 - diff / 2);
    }
    reverse(ALL(sb));
    cout << sa << endl;
    cout << sb << endl;
    return 0;
}
