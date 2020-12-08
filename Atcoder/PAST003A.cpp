#include<bits/stdc++.h>

using namespace std;


int main() {
	string s,t;
	cin >> s;
	cin >> t;

	int count = 0;
	
	for (int i = 0; i < 3; i++) {
		if (s[i] == t[i]) {
			count++;
		} else if (s[i]-32 == t[i] || s[i]+32 == t[i]) {
			continue;
		} else {
			cout << "different" << endl;
			return 0;
		}
	}

	if (count == 3) {
		cout << "same" << endl;
	} else {
		cout << "case-insensitive" << endl;
	}
	return 0;
}