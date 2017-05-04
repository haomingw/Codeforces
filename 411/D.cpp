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
#define SIZE(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int mod = 1e9 + 7;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0, cnt = 0;
    PER(i, n) {
        if (s[i] == 'b') cnt++;
        else ans = (ans + cnt) % mod, cnt = (cnt << 1) % mod;
    }
    cout << ans << endl;
    return 0;
}
