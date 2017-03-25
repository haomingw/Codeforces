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
typedef pair<string, string> pss;

const int maxn = 5005;
int val[maxn];
string smax, smin;

struct Exp {
    bool cst;
    int x, y;
    string s, op;
}e[maxn];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    string s, t;
    map<string, int> id;
    id["?"] = -1;
    REP(i, n) {
        cin >> t >> s;
        cin >> s;
        id[t] = i;
        if (s[0] == '0' || s[0] == '1') {
            e[i].cst = true;
            e[i].s = s;
        } else {
            e[i].x = id[s];
            cin >> s; e[i].op = s;
            cin >> s; e[i].y = id[s];
        }
    }
    int x, y, r, cnt[2];
    REP(i, m) {
        cnt[0] = cnt[1] = 0;
        REP(j, 2) {
            REP(k, n) {
                if (e[k].cst) val[k] = e[k].s[i] - '0';
                else {
                    x = e[k].x == -1 ? j : val[e[k].x];
                    y = e[k].y == -1 ? j : val[e[k].y];
                    if (e[k].op == "AND") r = x & y;
                    else if (e[k].op == "OR") r = x | y;
                    else r = x ^ y;
                    if (r == 1) cnt[j]++;
                    val[k] = r;
                }
            }
        }
        if (cnt[0] > cnt[1]) smax += '0', smin += '1';
        else if (cnt[0] < cnt[1]) smax += '1', smin += '0';
        else smax += '0', smin += '0';
    }
    cout << smin << endl;
    cout << smax << endl;
    return 0;
}
