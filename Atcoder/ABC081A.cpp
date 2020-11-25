#include<bits/stdc++.h>

using namespace std;

int main() {
	string s;
	int count = 0;

	cin >> s;
	for (char i : s) {
		if (i == '1') {
			count++;
		}
	}

	cout << count << endl;
	return 0;
}