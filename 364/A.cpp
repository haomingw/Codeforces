#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	int n;
	cin >> n;	
	int a[n];
	vector<pii> cards;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cards.push_back(make_pair(a[i], i + 1));
	}
	sort(cards.begin(), cards.end());	
	for (int i = 0; i < n / 2; i++) {
		cout << cards[i].second << " " << cards[n - 1 - i].second << endl;
	}
			
	return 0;
}