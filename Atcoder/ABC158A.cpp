#include<bits/stdc++.h>

using namespace std;

int main() {
	string S;
	cin >> S;
	
	for (int i = 0; i < 2; i++) {
		for (int j = i+1; j < 3; j++) {
			if (S[i] != S[j]) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}

	cout << "No" << endl;
	return 0;
}