#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;

typedef long long ll;

int main() {
    int n, k;
    cin >> n >> k;

    int c[n], id[k];
    ll sommes = 0;
    for (int i = 0; i < n; i++) {
	cin >> c[i];
	sommes += c[i];
    }
    for (int i = 0; i < k; i++) {
	cin >> id[i];
    }

    ll sum = 0, index = 0;
    unordered_map<int, int> hmap;
    for(int j = 0; j < k; j++) {
	index = id[j] - 1;
	// clog << index << endl;
	sum += c[index] * (sommes - c[index]);
	sommes -= c[index];
	hmap[index] = 1;
    }

    int prev, next;
    for (int i = 0; i < n; i++) {
	prev = i > 0 ? i - 1 : n - 1;
	next = (i + 1) % n;
	if (hmap.find(i) == hmap.end() && hmap.find(next) == hmap.end()) {
	    sum += c[i] * c[next];
	}
    }
    cout << sum << endl;
    return 0;
}
