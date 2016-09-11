#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n], b[n];
	for (int i = 0; i < n; i++) {
		// cin >> a[i];
		scanf("%d", &a[i]);
	}

	b[n - 1] = a[n - 1];	
	for (int i = 0; i < n - 1; i++) {
		b[i] = a[i] + a[i + 1];
		cout << b[i] << " ";
	}
	cout << b[n - 1] << endl;
	return 0;
}
