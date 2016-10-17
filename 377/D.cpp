#include <iostream>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <set>
using namespace std;

typedef pair<int, int> pii;

int main() {
    int n, m;
    cin >> n >> m;
    int d[n], a[m];
    set<pii> sub;
    for (int i = 0; i < n; i++)
        cin >> d[i];
    for (int i = 0; i < m; i++) {
        cin >> a[m];
        sub.insert({a[m], i});
    }
    sub.insert({1e6, 1e6});
    int ans = 0, cnt = 0;
    int cp = 0;
    for (int i = 0; i < n; i++) {
        auto p = sub.begin();
        int r = p->first, index = p->second;
        if (d[i] == 0) cnt++;
        else {
            if (cp > 0) {cp = max(cp - d[i], 0); ans = i + 1;}
            else cnt++;
        }
        if (!sub.empty() && cnt == r) {
            cnt = 0;
            cp++;
            sub.erase(p);
        }
    }
    if (cp == 0 && sub.size() == 1)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}
