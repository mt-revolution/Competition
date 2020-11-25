#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	string S;
	cin >> S;
	
	// RGBの累積和をそれぞれとる
	vector<long long> R_sum(N+1, 0), G_sum(N+1, 0), B_sum(N+1, 0);
	for (int i = 0; i < N; i++) {
		if (S[i] == 'R') {
			R_sum[i+1] = R_sum[i] + 1;
			G_sum[i+1] = G_sum[i];
			B_sum[i+1] = B_sum[i];
		} else if (S[i] == 'G') {
			G_sum[i+1] = G_sum[i] + 1;
			R_sum[i+1] = R_sum[i];
			B_sum[i+1] = B_sum[i];
		} else {
			B_sum[i+1] = B_sum[i] + 1;
			R_sum[i+1] = R_sum[i];
			G_sum[i+1] = G_sum[i];
		}
	}

	long long answer = 0;

	// iとjの2つを動かし、j以降のkについて先ほどの累積和を使って加算
	for (int i = 0; i < N-2; i++) {
		for (int j = i+1; j < N-1; j++) {
			if (S[i] == 'R' && S[j] == 'G') {
				if (2*j-i < N) {
					if (S[2*j-i] == 'B') {
						answer += B_sum[N] - B_sum[j] - 1;
						continue;
					}
				}
				answer += B_sum[N] - B_sum[j];
			} else if (S[i] == 'R' && S[j] == 'B') {
				if (2*j-i < N) {
					if (S[2*j-i] == 'G') {
						answer += G_sum[N] - G_sum[j] - 1;
						continue;
					}
				}
				answer += G_sum[N] - G_sum[j];
			} else if (S[i] == 'G' && S[j] == 'B') {
				if (2*j-i < N) {
					if (S[2*j-i] == 'R') {
						answer += R_sum[N] - R_sum[j] - 1;
						continue;
					}
				}
				answer += R_sum[N] - R_sum[j];
			} else if (S[i] == 'G' && S[j] == 'R') {
				if (2*j-i < N) {
					if (S[2*j-i] == 'B') {
						answer += B_sum[N] - B_sum[j] - 1;
						continue;
					}
				}
				answer += B_sum[N] - B_sum[j];
			} else if (S[i] == 'B' && S[j] == 'R') {
				if (2*j-i < N) {
					if (S[2*j-i] == 'G') {
						answer += G_sum[N] - G_sum[j] - 1;
						continue;
					}
				}
				answer += G_sum[N] - G_sum[j];
			} else if (S[i] == 'B' && S[j] == 'G') {
				if (2*j-i < N) {
					if (S[2*j-i] == 'R') {
						answer += R_sum[N] - R_sum[j] - 1;
						continue;
					}
				}
				answer += R_sum[N] - R_sum[j];
			}
		}
	}
	
	cout << answer << endl;
	return 0;
}