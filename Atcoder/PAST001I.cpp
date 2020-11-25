#include<bits/stdc++.h>

using namespace std;

const long long INF = 1000000000000000;

int main() {
	int N,M;
	cin >> N >> M;

	vector<string> S(M);
	vector<long long> C(M);
	for (int i = 0; i < M; i++) {
		cin >> S[i] >> C[i];
	}

	// 部品の集合jを揃えるのに必要な最小金額dp[j]
	vector<long long> dp(1<<N, INF);

	vector<int> S_bit(M, 0);
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (S[i][j] == 'Y') {
				S_bit[i] += pow(2, j);
			}
		}
	}

	// 初期条件
	dp[0] = 0;

	// dp開始
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < (1<<N); j++) {
			dp[j | S_bit[i]] = min(dp[j | S_bit[i]], dp[j] + C[i]);
		}
	}

	if (dp[(1<<N)-1] == INF) {
		cout << -1 << endl;
	} else {
		cout << dp[(1<<N)-1] << endl;
	}
	return 0;
}