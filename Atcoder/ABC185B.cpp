#include<bits/stdc++.h>

using namespace std;

int main() {
	int N,M,T;
	cin >> N >> M >> T;
	
	vector<int> A(M+2), B(M+2);

	for (int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i];
	}

	// B[0]をスタート、A[M+1]をゴールとしておく
	A[0] = 0, B[0] = 0;
	A[M+1] = T, B[M+1] = T;

	int tmp = N;

	for (int i = 1; i <= M+1; i++) {
		tmp -= A[i] - B[i-1];
		// バッテリー残量が下回ればアウト
		if (tmp <= 0) {
			cout << "No" << endl;
			return 0;
		}

		// バッテリー残量を足し、Nより大きくなるならNにする
		tmp += B[i] - A[i];
		tmp = min(tmp, N);
	}

	cout << "Yes" << endl;
	return 0;
}