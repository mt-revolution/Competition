#include<bits/stdc++.h>

using namespace std;

int main() {
	string S,T;
	cin >> S >> T;

	int S_size = S.size();
	int T_size = T.size();

	if (S.substr(0, S_size) == T.substr(0, S_size) && T_size == S_size + 1) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	return 0;
}