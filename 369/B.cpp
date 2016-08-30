# include <iostream>
typedef long long ll;
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[500][500];
	ll r[500], c[500], d1 = 0, d2 = 0;
	int x, y;	

	if (n == 1){
		cout << 1 << endl;
		return 0;
	}		
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++){
			cin >> a[i][j];
			if (a[i][j] == 0) {
				x = i; y = j;
			} else {
				r[i] += a[i][j];
				c[j] += a[i][j];
				if (i == j) {
					d1 += a[i][j];
				}
				if (i == n - 1 - j) {
					d2 += a[i][j];
				}									
			}
		}
	}
	ll cible = x == 0 ? r[1] : r[0];
	ll sub[2], ans;
	for (int i = 0; i < n; i++) {
		if (i != x) {
			if (r[i] != cible) {
				cout << -1 << endl;
				return 0;
			}
		} else {
			sub[0] = cible - r[i];
		}
		if (i != y) {
			if (c[i] != cible) {
				cout << -1 << endl;
				return 0;
			}
		} else {
			sub[1] = cible - c[i];
		}
	}
	if (sub[0] != sub[1] || sub[0] <= 0) {
		cout << -1 << endl;
		return 0;
	}
	ans = sub[0];
	if (x == y) { // check d1
		if (ans != cible - d1) {
			cout << -1 << endl;
			return 0;
		}
	} else if (cible != d1) {
		cout << -1 << endl;
		return 0;
	}
	
	if (x == n - 1 - y) { // check d2
		if (ans != cible - d2) {
			cout << -1 << endl;
			return 0;
		}
	} else if (cible != d2) {
		cout << -1 << endl;
		return 0;
	}
	
	cout << ans << endl;
	return 0;
}
