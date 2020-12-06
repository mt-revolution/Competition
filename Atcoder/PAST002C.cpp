#include<bits/stdc++.h>

using namespace std;


int main() {
	int N;
	cin >> N;
	
	vector<vector<char>> S(N+2, vector<char>(2*N+1, ' '));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 2*N-1; j++) {
			cin >> S[i][j];
		}
	}

	for (int i = N-1; i >= 1; i--) {
		for (int j = 2; j <= 2*N-2; j++) {
			if (S[i][j] == '#') {
				if (S[i+1][j-1] == 'X' || S[i+1][j] == 'X' || S[i+1][j+1] == 'X') {
					S[i][j] = 'X';
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 2*N-1; j++) {
			cout << S[i][j];
		}
		cout << endl;
	}
	return 0;
}