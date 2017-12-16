#include <iostream>
#include <set>
using namespace std;

typedef pair<int, int> pii;
set<int> s[300005];
set<pii> se;

int main() {
	int n, q;
	//cin >> n >> q;
	scanf("%d %d", &n, &q);

	int nx = 0;
	while (q--) {
		int type, x;
		//cin >> type >> x;
		scanf("%d %d", &type, &x);
		if (type == 1) {
			--x;
			s[x].insert(nx);
			se.insert(make_pair(nx, x));
			++nx;
		} else if (type == 2) {
			--x;
			for (auto & i : s[x]) {
				se.erase(make_pair(i, x));				
			}
			s[x].clear();
		} else { // type == 3
			while (!se.empty() && se.begin()->first < x) {
				pii p = *se.begin();
				se.erase(p);
				s[p.second].erase(p.first);
			}
		}
		cout << (int)se.size() << endl;
	}	
		
	return 0;
}