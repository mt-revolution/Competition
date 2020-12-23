#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	vector<int> p(N);
	for (int i = 0; i < N; i++) {
		cin >> p[i];
	}
	
	// i問まで解いたときの得点jにできるか
	vector<vector<int>> dp(N+1, vector<int>(10001, 0));

	// 初期条件
	dp[0][0] = 1;

	// dp開始
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= 10000; j++) {
			// 問題を解かないとき
			if (dp[i-1][j] > 0) {
				dp[i][j] = 1;
			}

			// 問題を解くとき
			if (j - p[i-1] >= 0) {
				if (dp[i-1][j - p[i-1]] > 0) {
					dp[i][j] = 1;	
				}
			}
		}
	}

	int answer = 0;
	for (int j = 0; j <= 10000; j++) {
		if (dp[N][j] > 0) {
			answer++;
		}
	}
	
	cout << answer << endl;
	return 0;
}