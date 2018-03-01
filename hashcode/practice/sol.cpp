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
#include <fstream>
using namespace std;

#define REPP(i,a,b) for(int i=(a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)
#define PER(i,a) for(int i = (a) - 1; i >= 0; --i)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

struct Slice {
    int i, j, w, h, count;
    Slice(int i, int j , int w, int h, int count): i(i), j(j), w(w), h(h), count(count) {}

    bool operator < (const Slice& b) {
        return count > b.count;
    }
};

const int maxn = 1005;
const int N = 5e6;
int height, width, L, H;
int pizza[maxn][maxn];
vector<pii> shapes;
vector<Slice> slices;
vector<int> ans;
bool conflicts[N];

void createShapes() {
    int s;
    REPP(w, 1, width + 1) REPP(h, 1, height + 1) {
        s = w * h;
        if (s < 2 * L) continue;
        if (s > H) break;
        shapes.push_back(MP(w, h));
    }
}

bool isLegal(int i, int j, int w, int h, int& sum) {
    if (i + h > height || j + w > width) return false;
    sum = 0;
    // can be optimized later
    REPP(a, i, i + h) REPP(b, j, j + w) sum += pizza[a][b];
    return min(sum, w * h - sum) >= L;
}

void createPossibleSlices() {
    createShapes();
    // int n = shapes.size();
    // REP(i, n) clog << shapes[i].first << " " << shapes[i].second << endl;
    int w, h, nb = 0;
    REP(i, height) REP(j, width) for (auto& shape : shapes) {
        w = shape.first, h = shape.second;
        if (isLegal(i, j, w, h, nb)) {
            slices.push_back(Slice(i, j, w, h, nb));
        }
    }
}

bool inSlice(int i, int j, const Slice& a) {
    return (i >= a.i && i < a.i + a.h && j >= a.j && j < a.j + a.w);
}

bool conflict(int a, int b) {
    if (a == b) return false;
    Slice sa = slices[a];
    REPP(i, sa.i, sa.i + sa.h) REPP(j, sa.j, sa.j + sa.w) {
        if (inSlice(i, j, slices[b])) return true;
    }
    return false;
}

void prepare() {
    createPossibleSlices();
    sort(ALL(slices));
    int n = slices.size();
    REP(i, n) conflicts[i] = false;
    //clog << "shape size " << shapes.size() << endl;
    //clog << "slice size " << slices.size() << endl;
}

bool can(int index) {
    for (int x : ans)
        if (conflict(x, index)) return false;
    return true;
}

void add(int index) {
    ans.push_back(index);
    clog << "adding slice #" << index << endl;
    int n = slices.size();
    REP(i, n) {
        if (!conflicts[i] && conflict(i, index)) conflicts[i] = true;
    }
}

void solve() {
    int n = slices.size();
    REP(i, n) {
        if (!conflicts[i]) add(i);
        // if (can(i)) ans.push_back(i);
    }
}

void print() {
    int n = ans.size(), score = 0;
    printf("%d\n", n);
    REP(i, n) {
        Slice s = slices[ans[i]];
        score += s.w * s.h;
        printf("%d %d %d %d\n", s.i, s.j, s.i + s.h - 1, s.j + s.w - 1);
    }
    clog << "score: " << score << endl;
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef LOCAL
    assert(argc == 2);
    string input = argv[1];
    assert(SZ(input) > 3 && input.substr(SZ(input) - 3) == ".in");
    string output = input.substr(0, input.size() - 3) + ".out";

    freopen(input.c_str(), "r", stdin);
    freopen(output.c_str(), "w", stdout);
#endif
    cin >> height >> width >> L >> H;
    string s;
    REP(i, height) {
        cin >> s;
        REP(j, width) pizza[i][j] = s[j] == 'T';
    }
    prepare();
    solve();
    print();
    return 0;
}
