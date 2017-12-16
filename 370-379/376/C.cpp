#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
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

const int N = 2e5 + 10;
int parent[N], size[N];
vector<vector<int> > mm;

int findParent(int i) {
    if (i != parent[i])
        parent[i] = findParent(parent[i]);
    return parent[i];
}

void setUnion(int l, int r) {
    int pl = findParent(l), pr = findParent(r);
    if (pl == pr) return;
    if (size[pl] >= size[pr]) {
        size[pl] += size[pr];
        parent[pr] = pl;
        mm[pl].insert(mm[pl].end(), ALL(mm[pr]));
    } else {
        size[pr] += size[pl];
        parent[pl] = pr;
        mm[pr].insert(mm[pr].end(), ALL(mm[pl]));
    }
    return;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int color[n];
    mm.resize(n);
    REP(i, n) scanf("%d",&color[i]);
    REP(i, n) parent[i] = i, size[i] = 1, mm[i].push_back(i);
    int l, r, ans = 0;
    REP(i, m) {
        scanf("%d %d", &l, &r);
        l--; r--;
        setUnion(l, r);
    }
    int vmax;
    map<int, int> cnt;
    REP(i, n) {
        if (findParent(i) == i) {
            vmax = 0;
            cnt.clear();
            REP(j, SIZE(mm[i])) {
                int sock = mm[i][j];
                int col = color[sock];
                cnt[col]++;
            }
            for (auto p : cnt)
                vmax = max(p.second, vmax);
            ans += size[i] - vmax;
        }
    }
    cout << ans << endl;
    return 0;
}
