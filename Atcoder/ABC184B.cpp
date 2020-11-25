#include<bits/stdc++.h>

using namespace std;

int main() {
	int N,X;
	cin >> N >> X;
	
	string S;
	cin >> S;
	
	int answer = X;
	for (int i = 0; i < N; i++) {
		if (S[i] == 'o') {
			answer += 1;
		} else if (S[i] == 'x') {
			if (answer != 0) {
				answer -= 1;
			}
		}
	}

	cout << answer << endl;
	return 0;
}