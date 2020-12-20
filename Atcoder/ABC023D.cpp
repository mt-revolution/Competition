#include<bits/stdc++.h>

using namespace std;

// 整数値のa/bの切り上げ値を求める
long long int_ceil(long long a, long long b) {
	return (a+(b-1))/b;
}


int main() {
	int N;
	cin >> N;
	
	vector<long long> H(N), S(N);
	for (int i = 0; i < N; i++) {
		cin >> H[i] >> S[i];
	}

	long long left = 1;
	long long right = 1000000000000000;
	long long mid;
	bool flag;

	// 高度X以内に全ての風船を割れるときのXを二分探索
	while (right - left > 1) {
		mid = (left + right)/2;
		flag = true;

		// それぞれの風船が高度Xより大きくなるまでの制限時間
		vector<pair<long long, int>> limit_time(N);
		for (int i = 0; i < N; i++) {
			// そもそも最初の高度がXより大きいとき
			if (mid < H[i]) {
				flag = false;
				break;
			}

			limit_time[i] = make_pair((mid - H[i]) / S[i], i);
		}

		// 制限時間の小さい順に並べる
		sort(limit_time.begin(), limit_time.end());

		// 時刻t(0からN-1)までに制限時間がおさまっているか確認
		for (int t = 0; t < N; t++) {
			if (limit_time[t].first < t) {
				flag = false;
				break;
			}
		}

		// 収まっていなければより大きいXの範囲で調べる
		if (flag == false) {
			left = mid;
			continue;
		}
		
		// 収まっていればより小さいXの範囲で調べる
		right = mid;
	}

	cout << right << endl;
	return 0;
}