#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<long long> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	// カウント用
	vector<long long> count(200001, 0);

	// それぞれの数についてj-A[j]を記録
	for (int j = 0; j < N; j++) {
		if (j - A[j] >= 0 && j - A[j] <= 200000) {
			count[j-A[j]] += 1;	
		}
	}

	long long answer = 0;

	// それぞれの数についてi+A[i]と一致する組み合わせの数を足していく
	for (int i = 0; i < N; i++) {
		if (i + A[i] >= 0 && i + A[i] <= 200000) {
			answer += count[i+A[i]];
		}
	}
	
	cout << answer << endl;
	return 0;
}