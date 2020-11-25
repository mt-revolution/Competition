#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
	long long K;
	cin >> N >> K;

	vector<int> P(N+1);
	vector<long long> C(N+1);
	vector<vector<int>> path(N+1, vector<int>{});
	vector<int> id(N+1, 0);
	vector<long long> loop(N+1, 0);
	vector<vector<long long>> loop_current(N+1, vector<long long>{});
	vector<long long> loop_sum(N+1, 0);
	int P_tmp = 0;

	for (int i = 1; i <= N; i++) {
		cin >> P[i];
	}

	for (int i = 1; i <= N; i++) {
		cin >> C[i];
	}

	// ループの情報を処理
	for (long long i = 1; i <= N; i++) {
		id.assign(N+1, 0);
		P_tmp = i;
		id[i] += 1;
		long long current = 0;

		while (1) {
			
			P_tmp = P[P_tmp];
			path[i].push_back(P_tmp);
			id[P_tmp] += 1;
			current += C[P_tmp];
			loop_current[i].push_back(current);

			if (id[i] == 2) {
				break;
			}
		}

		loop[i] = path[i].size();
		loop_sum[i] = loop_current[i].back();
	}

	vector<long long> max_point(N+1, -1e18);

	// それぞれのスタート地点からK回以下での最大値を求める
	for (int i = 1; i <= N; i++) {
		// ループ回数がK回より大きい場合
		if (loop[i] > K) {
			for (int j = 0; j < K; j++) {
				max_point[i] = max(max_point[i], loop_current[i][j]);
			}

			
		} else {
			if (loop_sum[i] <= 0) {
				for (auto j : loop_current[i]) {
					max_point[i] = max(max_point[i], j);
				}
			} else {
				long long loop_number = K / loop[i];
				long long rest = K % loop[i];

				if (rest == 0) {
					loop_number -= 1;
					rest = loop[i];
				}

				for (int j = 0; j < rest; j++) {
					max_point[i] = max(max_point[i], loop_sum[i] * loop_number + loop_current[i][j]);
				}

				for (auto j : loop_current[i]) {
					max_point[i] = max(max_point[i], loop_sum[i] * (loop_number-1) + j);
				}
			}
		}
	}

	long long answer = -1e18;

	for (int i = 1; i <= N; i++) {
		answer = max(answer, max_point[i]);
	}

	cout << answer << endl;
	return 0;
}