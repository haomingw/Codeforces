#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	char l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> l;
			if (l == 'C' || l == 'M' || l == 'Y') {
				cout << "#Color" << endl;
				return 0;
			}
		}
	}
	cout << "#Black&White" << endl;
	return 0;
}