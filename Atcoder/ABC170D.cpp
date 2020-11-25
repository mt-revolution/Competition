#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	sort(A.begin(), A.end());

	vector<pair<int,int>> run_length;
	int tmp = A[0], tmp_count = 1;

	// ランレングス圧縮
	for (int i = 1; i < N; i++) {
		if (A[i] == tmp) {
			tmp_count += 1;
		} else {
			run_length.push_back(make_pair(tmp, tmp_count));
			tmp = A[i];
			tmp_count = 1;
		}
	}

	run_length.push_back(make_pair(tmp, tmp_count));

	// Aから同じ数字を除いたもの
	vector<int> A_;

	// 同じ数カウント用
	vector<bool> same_num(1000001, false);

	// ランレングス復元
	for (auto pair : run_length) {
		if (pair.second > 1) {
			same_num[pair.first] = true;
		}
		
		A_.push_back(pair.first);
	}

	// 約数カウント用
	vector<long long> divisor(1000001, 0);

	int answer = 0;

	for (int i = 0; i < A_.size(); i++) {
		// 約数の数が0で同じ数がなかったときに答えに含める
		if (divisor[A_[i]] == 0) {
			if (same_num[A_[i]] == false) {
				answer++;			
			}
		}

		// その数の倍数を約数の個数にカウント
		for (int j = A_[i]; j <= 1000000; j += A_[i]) {
			divisor[j] += 1;
		}
	}

	cout << answer << endl;
	return 0;
}