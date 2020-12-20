#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	vector<long long> A(N);
	vector<long long> A_sum(N+1);
	
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	sort(A.begin(), A.end());

	// 累積和
	A_sum[0] = 0;
	for (int i = 0; i < N; i++) {
		A_sum[i+1] = A_sum[i] + A[i];
	}

	long long answer = 0;

	// abs(項数*見ている項 - その項より右の項の和)を足していく
	for (int i = 0; i < N-1; i++) {
		answer += abs((N-1-i) * A[i] - (A_sum[N] - A_sum[i+1]));
	}

	cout << answer << endl;
	return 0;
}