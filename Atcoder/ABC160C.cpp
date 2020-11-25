#include<bits/stdc++.h>

using namespace std;

int main() {
	int K,N;
	cin >> K >> N;
	
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int max_distance = 0, distance;

	for (int i = 0; i < N; i++) {
		// 端の家の処理
		if (i == N-1) {
			distance = abs(A[i] - A[0]);
			max_distance = max(max_distance, min(distance, K - distance));
			continue;
		}

		// 家同士の距離
		distance = abs(A[i] - A[i+1]);
		// 円形の家同士の距離の短い方を最大値の候補とする
		max_distance = max(max_distance, min(distance, K - distance));
	}

	// 答えは1周の長さから家の距離の最大値をひいた値
	int answer = K - max_distance;

	cout << answer << endl;
	return 0;
}