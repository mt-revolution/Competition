#include<bits/stdc++.h>

using namespace std;

int main() {
	string N;
	cin >> N;
	
	int N_size = N.size();
	vector<int> num(N_size);

	// 各桁の数取得
	for (int i = 0; i < N_size; i++) {
		num[i] = N[i] - '0';
	}

	int answer = 1000000000;
	int digit_count = 0, sum = 0;

	// ビット全探索で各桁の数字の全ての組み合わせを調べる
	for (int bit = 1; bit < (1<<N_size); bit++) {
		digit_count = 0;
		sum = 0;

		// 和を計算
		for (int i = 0; i < N_size; i++) {
			if (bit & 1<<i) {
				digit_count += 1;
				sum += num[i];
			}
		}

		// 最小値の更新
		if (sum % 3 == 0) {
			answer = min(answer, N_size - digit_count);
		}
	}

	if (answer == 1000000000) {
		cout << -1 << endl;
	} else {
		cout << answer << endl;
	}

	return 0;
}