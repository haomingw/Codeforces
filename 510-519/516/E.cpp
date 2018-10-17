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
    int n; cin >> n;
    string s;
    map<int, bool> mp;
    cout << "0 1" << endl;
    cin >> s;
    mp[0] = s[0] == 'b';
    int l = 0, r = 1e9;
    REP(i, n - 1) {
        int mid = (l + r) / 2;
        cout << mid << " 1" << endl;
        cin >> s;
        mp[mid] = s[0] == 'b';
        if (mp[mid] == mp[0]) l = mid;
        else r = mid;
    }
    cout << l << " 2 " << r << " 0" << endl;
    return 0;
}
