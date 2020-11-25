#include<bits/stdc++.h>

using namespace std;

int main() {
	string S;
	cin >> S;

	int count = 0;

	for(int i = 0; i < 3; i++) {
		if(i == 0 && S[i] == 'R' && S[i+1] == 'R' && S[i+2] == 'R') {
			count = 3;
			break;
		}
		if(i != 2 && S[i] == 'R' && S[i+1] == 'R') {
			count = 2;
			break;
		}
		if(S[i] == 'R') {
			count = 1;
			break;
		}
	}
	cout << count << endl;
	return 0;
}