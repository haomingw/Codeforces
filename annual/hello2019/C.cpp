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
#include <cassert>
using namespace std;
#define REPP(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)
#define PER(i,a) for(int i = (a) - 1; i >= 0; --i)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    string s;
    int ans = 0;
    vector<int> a;
    REP(i, n) {
        cin >> s;
        int cnt_open = 0, cnt_close = 0;
        for (char c : s) {
            if (c == '(') cnt_open++;
            else cnt_close++;
        }
        int bal = 0;
        for (char c : s) {
            if (c == '(') bal++;
            else if (bal > 0) {
                cnt_open--, cnt_close--;
                bal--;
            }
        }
        if (cnt_open > 0 && cnt_close > 0) continue;
        a.push_back(cnt_open - cnt_close);
    }
    sort(a.begin(), a.end());
    int l = 0, h = a.size() - 1;
    while (l < h) {
        if (a[l] + a[h] == 0) {
            ans++;
            l++, h--;
        } else if (a[l] + a[h] > 0) {
            h--;
        } else {
            l++;
        }
    }
    cout << ans << endl;
    return 0;
}
