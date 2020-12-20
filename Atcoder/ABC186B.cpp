#include<bits/stdc++.h>

using namespace std;

int main() {
	int H,W;
	cin >> H >> W;
	
	int answer = 0;
	int min_A = 1000000000;
	vector<vector<int>> A(H, vector<int>(W));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> A[i][j];
			min_A = min(min_A, A[i][j]);
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			answer += A[i][j] - min_A;	
		}
	}

	cout << answer << endl;
	return 0;
}