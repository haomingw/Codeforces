#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <climits>
using namespace std;

typedef long long ll;

int compare(string a, string b) {
	return a.compare(b);
}

string reverse(string s) {
	reverse(s.begin(), s.end());
	return s;
}

const ll INF = LLONG_MAX;

int main() {
	int n;
	cin >> n;
	ll c[n];
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}	
	string str;
	vector<string> vs;
	ll dp[n][2];
	for (int i = 0; i < n; i++) {		
		cin >> str;
		vs.push_back(str);
		dp[i][0] = dp[i][1] = INF;		
	}
		
	dp[0][0] = 0;
	dp[0][1] = c[0];							
	for (int i = 1; i < n; i++) {						
		bool flag1 = false, flag2 = false;
		bool f1 = compare(vs[i], vs[i-1]) >= 0, f2 = compare(reverse(vs[i]), vs[i-1]) >= 0;
		if (f1 || f2) {
			if (dp[i-1][0] != INF) {
				if (f1)									
					dp[i][0] = min(dp[i][0], dp[i-1][0]);
				if (f2)									
					dp[i][1] = min(dp[i][1], dp[i-1][0] + c[i]);				
			}
		} else {
			flag1 = true;
		}
		bool f3 = compare(vs[i], reverse(vs[i-1])) >= 0, f4 = compare(reverse(vs[i]), reverse(vs[i-1])) >= 0;
		if (f3 || f4) {
			if (dp[i-1][1] != INF) {
				if (f3)
					dp[i][0] = min(dp[i][0], dp[i-1][1]);
				if (f4)
					dp[i][1] = min(dp[i][1], dp[i-1][1] + c[i]);				
			}
		} else{
			flag2 = true;
		}

		if (flag1 && flag2) {			
			cout << -1 << endl;
			return 0;
		}				
	}	
	ll ans  = min(dp[n - 1][0], dp[n - 1][1]);
	if (ans == INF)
		ans = -1;
	cout << ans << endl;	
	return 0;
}