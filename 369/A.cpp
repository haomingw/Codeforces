#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	bool flag = false;
	string s[1001];

	for (int i = 0; i < n; i++) {
		cin >> s[i];
		if (flag)
			continue;
		if (s[i][0] == 'O' && s[i][1] == 'O') {
			flag = true;
			s[i].replace(0, 2, "++");
		} else if (s[i][3] == 'O' && s[i][4] == 'O') {
			flag = true;
			s[i].replace(3, 2, "++");
		}
	}
	if (flag) {
		cout << "YES" << endl;
		for (int i = 0 ; i < n; i++) {
			cout << s[i] << endl;
		}
	} else {
		cout << "NO" << endl;
	}
	return 0;
}