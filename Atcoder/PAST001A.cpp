#include<bits/stdc++.h>

using namespace std;

int main() {
	string S;
	cin >> S;
	
	for (int i = 0; i < 3; i++) {
		if (S[i] >= 'a' && S[i] <= 'z') {
			cout << "error" << endl;
			return 0;
		}
	}

	int num = 2 * stoi(S);
	cout << num << endl;
	return 0;
}