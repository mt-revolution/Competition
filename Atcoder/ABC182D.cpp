#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	vector<long long> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	vector<long long> A_sum(N+1), A_sum_max(N+1);
	A_sum[0] = 0, A_sum_max[0] = 0;

	// 累積和と今まで見た累積和の最大値を記録
	for (int i = 1; i <= N; i++) {
		A_sum[i] = A_sum[i-1] + A[i-1];
		A_sum_max[i] = max(A_sum_max[i-1], A_sum[i]);
	}

	vector<long long> A_sum_2(N+1), A_sum_2_max(N+1);
	A_sum_2[0] = 0, A_sum_2_max[0] = 0;

	long long answer = -100000000000000000;

	// 各操作を始める前の値を記録し、各操作の中での最大値を累積和の最大値を使って求める
	for (int i = 1; i <= N; i++) {
		A_sum_2[i] = A_sum_2[i-1] + A_sum[i];
		A_sum_2_max[i] = A_sum_2[i-1] + A_sum_max[i];

		answer = max(answer, A_sum_2_max[i]);
	}

	cout << answer << endl;
	return 0;
}