#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

bool isDigit(char a) {
    return (a >= '0' && a <= '9') || a == '.';
}

vector<int> parse(string a) {
    int m = 0, c = 0, cnt = 0;
    vector<int> res;
    int n = a.size();
    bool isDouble = n > 3 && a[n - 3] == '.';
    if (!isDouble) {
        for (int i = 0; i < n; i++) {
            if (a[i] == '.') continue;
            m = m * 10 + a[i] - '0';
        }
    } else {
        for (int i = 0; i < n - 3; i++) {
            if (a[i] == '.') continue;
            m = m * 10 + a[i] - '0';
        }
        c = (a[n - 2] - '0') * 10 + (a[n - 1] - '0');
    }
    res.push_back(m);
    res.push_back(c);
    return res;
}

string to_num(int a) {
    string s = to_string(a);
    if (a < 1000) return s;
    int n = s.size(), cnt = n - 3;
    string ans = "";
    while (cnt >= 0) {
        ans = s.substr(cnt, 3) + ans;
        if (cnt > 0) ans = "." + ans;
        cnt -= 3;
        if (cnt < 0) ans = s.substr(0, cnt + 3) + ans;
    }
    return ans;
}

string add(string a, string b) {
    if (a.size() == 0) return b;
    vector<int> ap = parse(a), bp = parse(b);
    int entier = ap.at(0) + bp.at(0), cent = ap.at(1) + bp.at(1);
    if (cent >= 100) {
        cent -= 100;
        entier++;
    }
    if (cent == 0) return to_num(entier);
    string c = to_string(cent);
    if (cent < 10) c = "0" + c;
    return to_num(entier) + "." + c;
}

string solve(vector<string> p) {
    string ans = "";
    for (int i = 0; i < p.size(); i++) {
        ans = add(ans, p.at(i));
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    clog << s.size() << ", " << s << endl;
    int debut = 0;
    vector<string> prices;
    bool prev = false, now = false;
    for (int i = 0; i < s.size(); i++) {
        now = isDigit(s[i]);
        if (!prev && now) debut = i;
        if (prev && !now) {
            prices.push_back(s.substr(debut, i - debut));
        }
        prev = now;
    }
    if (now) prices.push_back(s.substr(debut, s.size()));

    cout << solve(prices) << endl;
    return 0;
}
