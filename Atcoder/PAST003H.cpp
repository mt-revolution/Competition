#include<bits/stdc++.h>

using namespace std;


int main() {
	int N,L;
	cin >> N >> L;
	
	vector<bool> hurdle(L+1, false);
	int x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		hurdle[x] = true;
	}

	vector<int> T(3);
	for (int i = 0; i < 3; i++) {
		cin >> T[i];
	}

	int INF = 1000000000;

	// 座標iまでにかかる最短の秒数dp[i]
	vector<int> dp(L+1, INF);

	// 初期条件
	dp[0] = 0;

	// dp開始、ハードルがある場合T[2]を足す
	for (int i = 0; i < L; i++) {
		// 行動1
		if (hurdle[i] == true) {
			dp[i+1] = min(dp[i+1], dp[i] + T[0] + T[2]);
			
		} else {
			dp[i+1] = min(dp[i+1], dp[i] + T[0]);
		}

		// 行動2
		if (hurdle[i] == true) {
			if (L == i+1) {
				dp[L] = min(dp[L], dp[i] + T[0]/2 + T[1]/2 + T[2]);
			} else {
				dp[i+2] = min(dp[i+2], dp[i] + T[0] + T[1] + T[2]);
			}
			
		} else {
			if (L == i+1) {
				dp[L] = min(dp[L], dp[i] + T[0]/2 + T[1]/2);
			} else {
				dp[i+2] = min(dp[i+2], dp[i] + T[0] + T[1]);
			}
		}

		// 行動3
		if (hurdle[i] == true) {
			if (L >= i+1 && L <= i+3) {
				dp[L] = min(dp[L], dp[i] + T[0]/2 + T[1]/2 + T[1]*(L-i-1) + T[2]);
			} else {
				dp[i+4] = min(dp[i+4], dp[i] + T[0] + 3*T[1] + T[2]);
			}
			
		} else {
			if (L >= i+1 && L <= i+3) {
				dp[L] = min(dp[L], dp[i] + T[0]/2 + T[1]/2 + T[1]*(L-i-1));
			} else {
				dp[i+4] = min(dp[i+4], dp[i] + T[0] + 3*T[1]);
			}
		}

	}

	cout << dp[L] << endl;
	return 0;
}