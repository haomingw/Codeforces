#include <iostream>
#include <cstring>
#include <algorithm>
#include <valarray>
using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	int x[n];	
	for (int i = 0; i < n; i++) {
		cin >> x[i];				
	}
	int q, ans;
	ll m;
	cin >> q;
	sort(x, x + n);		
	for (int i = 0; i < q; i++) {		
		cin >> m;
		ans = upper_bound(x, x + n, m) - x;
		cout << ans << endl;
	}	
	return 0;
}