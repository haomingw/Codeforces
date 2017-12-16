#include <iostream>
#include <unordered_map>
using namespace std;

int imax = 1e9;
int main() {
	string s;
	cin >> s;
	unordered_map<char, int> hmap;
	int n = s.size(), h, v, ans;

	for (int i = 0; i < n; i++) {
		if (hmap.find(s[i]) != hmap.end()) {
			hmap[s[i]] += 1;
		} else {
			hmap[s[i]] = 1;
		}
	}

	int l = hmap['L'], r = hmap['R'], u = hmap['U'], d = hmap['D'];
	int d1 = abs(l - r), d2 = abs(u - d);
	int diff = abs(d2 - d1);
	if (d1 < d2) {
		h = imax;
		if (diff % 2 != 0) {
			v = imax;
		} else {
			v = d1 + diff / 2;
		}
	} else if (d1 == d2) {
		v = h = d1;
	} else { // d1 > d2
		v = imax;	
		if (diff % 2 != 0) {
			h = imax;
		} else {
			h = d2 + diff / 2;
		}
	}
	// clog << d1 << ", " << d2 << endl; 
	ans = h == imax && v == imax ? -1 : min(h, v);			
	cout << ans << endl;
	return 0;	
}