#include<bits/stdc++.h>

using namespace std;

int main() {
	int N,M,X;
	cin >> N >> M >> X;

	vector<int> C(N);
	vector<vector<int>> A(N, vector<int>(M));
	vector<int> sum(M, 0);
	int answer = 1000000000;
	int sum_money = 0;
	bool flag = true;

	for (int i = 0; i < N; i++) {
		cin >> C[i];

		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}

	// ビット全探索
	for (int bit = 0; bit < (1<<N); bit++) {
		sum.assign(M, 0);
		sum_money = 0;
		flag = true;

		// それぞれの参考書について
		for (int i = 0; i < N; i++) {
			// 参考書を買う場合
			if (bit & (1<<i)) {
				sum_money += C[i];

				// その参考書のそれぞれの理解度を加算
				for (int j = 0; j < M; j++) {
					sum[j] += A[i][j];
				}
			}
		}

		// それぞれの理解度がXを上回っているか確認
		for (int j = 0; j < M; j++) {
			if (sum[j] < X) {
				flag = false;
				break;
			}
		}

		// 上回っていない場合
		if (flag == false) {
			continue;
		}

		// 最小値更新
		answer = min(answer, sum_money);
	}

	// 条件を満たさない場合
	if (answer == 1000000000) {
		cout << -1 << endl;
	// 条件を満たす場合
	} else {
		cout << answer << endl;
	}

	return 0;
}