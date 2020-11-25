#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
	long long K;
	cin >> N >> K;

	vector<int> A(N+1);
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	// ワープの変遷
	vector<int> trans;
	// 重複チェック
	vector<int> id(N+1, 0);
	int tmp = 1;
	int next;

	trans.push_back(1);
	id[1] = 1;

	// 変遷の記録をする
	while (1) {
		next = A[tmp];
		if (id[next] == 1) {
			trans.push_back(next);
			break;
		}

		tmp = next;
		id[tmp] = 1;

		trans.push_back(tmp);
	}

	// ループの始まるインデックス
	int loop_start;

	for (int i = 0; i < trans.size() - 1; i++) {
		if (trans[i] == trans.back()) {
			loop_start = i;
			break;
		}
	}
	
	// ループする前の変遷
	vector<int> before;
	// ループの変遷
	vector<int> loop;

	for (int i = 0; i < loop_start; i++) {
		before.push_back(trans[i]);
	}

	for (int i = loop_start; i < trans.size() - 1; i++) {
		loop.push_back(trans[i]);
	}

	long long before_size = before.size(), loop_size = loop.size();

	int answer;

	// ワープ回数が少なくループする前の変遷で決まるとき
	if (K < before_size) {
		answer = before[K];
	// ワープ回数が多くループの変遷で決まるとき
	} else {
		K -= before_size;
		answer = loop[K % loop_size];
	}
	
	cout << answer << endl;
	return 0;
}