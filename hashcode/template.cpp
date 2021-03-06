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
#include <numeric>
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

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false), cin.tie(0);
#ifdef LOCAL
    assert(argc == 2);
    string input = argv[1], ext = ".txt";
    assert(SZ(input) > SZ(ext) && input.substr(SZ(input) - SZ(ext)) == ext);
    string output = "output/" + input.substr(0, input.size() - SZ(ext)) + ".submit";

    freopen(input.c_str(), "r", stdin);
    freopen(output.c_str(), "w", stdout);
#endif

    return 0;
}
