#include <iostream>
// #include <cstdio>
#include <map>
using namespace std;

typedef long long ll;
map<int, int> hmap;

int main() {
	int q;
	cin >> q;
	
	char c;
	int x, l, h, t, b;
	while (q--) {				
		// cin >> c >> x;
		scanf(" %c %d", &c, &x); // faster than cin
		if (c == '+') {
			hmap[x]++;
		} else if (c == '-'){
			hmap[x]--;
			if (hmap[x] == 0)
				hmap.erase(x);			
		} else { // find max value
			l = 0;
			h = ((ll)1 << 31) - 1;
			t = h ^ x; // this is the target we want to find in A

			for (int i = 30; i >= 0; i--) {
				b = t & (1 << i);
				if (b) { // i th target bit is 1
					h = h | (1 << i);
					l = l | (1 << i);
					if (hmap.lower_bound(l) == hmap.upper_bound(h)) { // no value between l and h
						// reverse
						h = h & (~(1 << i));
						l = l & (~(1 << i));
					}
				} else {
					h = h & (~(1 << i));
					l = l & (~(1 << i));
					if (hmap.lower_bound(l) == hmap.upper_bound(h)) { // no value between l and h
						h = h | (1 << i);
						l = l | (1 << i);
					}
				}
			}
			cout << max(x, l^x) << endl;
		}		
	}	
	return 0;
}