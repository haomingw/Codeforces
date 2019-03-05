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
#include <random>
using namespace std;

#define REPP(i,a,b) for(int i=(a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)
#define PER(i,a) for(int i = (a) - 1; i >= 0; --i)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 1e5 + 5;
map<string, int> mp;
int n, cnt;
bool vis[maxn];

struct Photo {
    // 0: Horizontal, 1: vertical
    int id;
    bool is_vertical;
    vector<int> tags;

    Photo(int id, char c) {
        this->id = id;
        is_vertical = c == 'V';
    }

    void add_tag(string& t) {
        if (!mp.count(t)) {
            cnt++;
            mp[t] = cnt;
        }
        tags.push_back(mp[t]);
    }

    void sort_tags() {
        sort(ALL(tags));
    }

    int intersect(Photo& other) {
        map<int, bool> t;
        for (int x : tags) t[x] = true;
        int count = 0;
        for (int x : other.tags) if (t.count(x)) cnt++;
        return count;
    }
};

bool operator < (const Photo& a, const Photo& b) {
    return a.tags < b.tags;
}

ostream& operator << (ostream& out, const Photo& photo) {
    out << "id: " << photo.id << ", is_vertical: " << photo.is_vertical;
    out << ", contains ";
    for (int x : photo.tags) cout << x << " ";
    return out;
}

struct Slide {
    vector<int> id;
    set<int> tags;

    Slide(Photo& a) {
        assert(!a.is_vertical);
        id.push_back(a.id);
        for (int x : a.tags) tags.insert(x);
    }

    Slide(Photo& a, Photo& b) {
        assert(a.is_vertical && b.is_vertical);
        id = {a.id, b.id};
        for (int x : a.tags) tags.insert(x);
        for (int x : b.tags) tags.insert(x);
    }
};

ostream& operator << (ostream& out, const Slide& slide) {
    for (int x : slide.id) cout << x << " ";
    return out;
}

vector<Photo> photos;
vector<Slide> slides;
vector<int> result;

int score(Slide& a, Slide& b) {
    set<int> sect;
    set_intersection(ALL(a.tags), ALL(b.tags), inserter(sect, sect.begin()));
    // for (int x : sect) clog << x << " "; clog << endl;
    int a1 = a.tags.size(), c = sect.size(), b1 = b.tags.size();
    int res = min(min(a1 - c, b1 - c), c);
    return res;
}

void prepare() {
    cin >> n;
    char c;
    int m;
    string s;
    REP(i, n) {
        cin >> c >> m;
        photos.push_back(Photo(i, c));
        REP(j, m) {
            cin >> s;
            photos.back().add_tag(s);
        }
    }
    vector<Photo> v;
    for (auto& photo : photos) {
        if (!photo.is_vertical && photo.tags.size() == 1)
            continue;
        if (photo.is_vertical) {
            photo.sort_tags();
            v.push_back(photo);
        } else {
            slides.push_back(Slide(photo));
        }
    }
    sort(ALL(v));
    m = v.size();
    REP(i, m) {
        if (i + m / 2 >= m) break;
        slides.push_back(Slide(v[i], v[i + m / 2]));
    }
    clog << "slides: " << slides.size() << endl;
}

void slideshow() {
    int m = slides.size();
    int start = 0;
    vis[start] = true;
    result.push_back(start);

    int prev = start;
    int count = 0;
    while (true) {
        count++;
        clog << count << endl;
        int note = 0, id = -1, x;
        REP(i, m) if (!vis[i]) {
            x = score(slides[prev], slides[i]);
            if (x > note) {
                note = x;
                id = i;
            }
        }
        if (id < 0) break;
        prev = id;
        vis[id] = true;
        result.push_back(id);
    }
}

void print() {
    cout << result.size() << endl;
    for (int x : result) {
        cout << slides[x] << endl;
    }
}

void solve() {
    prepare();
    slideshow();
    print();
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef LOCAL
    assert(argc == 2);
    string input = argv[1];
    assert(SZ(input) > 3 && input.substr(SZ(input) - 3) == ".in");
    string output = "output/" + input.substr(0, input.size() - 3) + ".out";

    freopen(input.c_str(), "r", stdin);
    freopen(output.c_str(), "w", stdout);
#endif
    solve();
    return 0;
}
