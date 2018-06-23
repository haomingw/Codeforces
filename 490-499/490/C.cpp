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

#define REPP(i,a,b) for(int i=(a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)
#define PER(i,a) for(int i = (a) - 1; i >= 0; --i)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<pii> v;
    REP(i, n) v.push_back(MP(s[i] - 'a', i));
    sort(ALL(v));
    map<int, bool> mp;
    REP(i, k) mp[v[i].second] = true;
    string t = "";
    REP(i, n) if (!mp.count(i)) t += s[i];
    cout << t << endl;
    return 0;
}
