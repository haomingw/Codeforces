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
#include <bitset>
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
typedef pair<int, vector<int> > piv;

int nbooks, nlibs, ndays;
int result;
vector<int> score;
vector<bool> used;
vector<piv> res;

struct Library {
  int id;
  int n;
  int signup;
  int ship;
  vector<int> books;

  void read(int _id) {
    id = _id;
    cin >> n >> signup >> ship;
    books.resize(n);
    for (int& book : books) cin >> book;
    sort(books.begin(), books.end(), [&](const int a, const int b) {
      return score[a] > score[b];
    });
  }

  double simulate(int start, int indeed) {
    start += signup;
    int total = 0;
    double wasted = signup;
    // wasted += 0.1 * max(ndays - (start + n / ship), 0);  // for F
    vector<int> selected;
    int cnt = 0, m = min((ndays - start) * ship, n);
    REP(i, n) if (!used[books[i]]) {
      if (cnt >= m) break;
      total += score[books[i]];
      if (indeed) {
        selected.push_back(books[i]);
        used[books[i]] = true;
      }
      cnt++;
    }
    if (indeed && !selected.empty()) {
      res.emplace_back(id, selected);
      result += total;
    }
    return total / wasted;
  }

};

bool operator < (const Library& a, const Library& b) {
  int ra = a.n / a.ship, rb = b.n / b.ship;
  if (ra != rb) return ra > rb;
  return a.signup < b.signup;
}

ostream& operator << (ostream& out, const Library& lib) {
    out << "id: " << lib.id << "\t signup: " << lib.signup;
    out << "\t ship: " << lib.ship << "\t books: " << lib.n;
    return out;
}

vector<Library> libs;

void init() {
  cin >> nbooks >> nlibs >> ndays;

  used.resize(nbooks);
  score.resize(nbooks);
  libs.resize(nlibs);

  for (int& x : score) cin >> x;
  REP(i, nlibs) libs[i].read(i);
}

void select() {
  int start = 0;
  map<int, bool> vis;

  while (start < ndays) {
    double best = 0;
    int best_id = -1;
    REP(i, nlibs) if (!vis.count(i)) {
      double t = libs[i].simulate(start, false);
      if (t > best) best = t, best_id = i;
    }
    // clog << start << endl;
    // clog << "best: " << best  << ", best_id: " << best_id << endl;
    if (best_id < 0) break;
    libs[best_id].simulate(start, true);
    vis[best_id] = true;
    start += libs[best_id].signup;
    // clog << res.back().first << " " << res.back().second.size() << endl;
    // clog << libs[best_id] << endl;
  }
}

void simulate(vector<int>& selected) {
  int start = 0;
  result = 0;
  res.clear();
  REP(i, nbooks) used[i] = false;
  for (int x : selected) {
    libs[x].simulate(start, true);
    start += libs[x].signup;
    if (start >= ndays) break;
  }
}

bool local_search() {
  map<int, bool> vis;
  vector<int> current;
  for (piv& p : res) {
    vis[p.first] = true;
    current.push_back(p.first);
  }
  REP(i, nlibs) if (!vis.count(i)) current.push_back(i);
  int n = res.size();
  int best = result;
  clog << "best: " << best << endl;
  vector<int> solution = current;
  bool ok = false;
  REP(i, n) REPP(j, i + 1, nlibs) {
    swap(current[i], current[j]);
    simulate(current);
    if (result > best) {
      clog << "found better solution: from " << best << " to " << result << endl;
      best = result;
      solution = current;
      ok = true;
    }
    swap(current[i], current[j]);
  }
  simulate(solution);
  return ok;
}

void print() {
  cout << res.size() << endl;
  for (piv& p: res) {
    cout << p.first << " " << p.second.size() << endl;
    for (int x : p.second) cout << x << " ";
    cout << endl;
  }
  clog << "result: " << result << endl;
}

void solve() {
  init();
  select();
  while (local_search());
  print();
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef LOCAL
  assert(argc == 2);
  string input = argv[1], ext = ".in";
  assert(SZ(input) > SZ(ext) && input.substr(SZ(input) - SZ(ext)) == ext);
  string output = "output/" + input.substr(0, input.size() - SZ(ext)) + ".out";

  freopen(input.c_str(), "r", stdin);
  freopen(output.c_str(), "w", stdout);
#endif
  solve();
  return 0;
}
