#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
	long long K;
	cin >> N >> K;

	vector<vector<long long>> T(N, vector<long long>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> T[i][j];
		}
	}

	// 順列用の配列を生成
	vector<int> p;
	for (int i = 1; i < N; i++) {
		p.push_back(i);
	}

	long long count = 0;
	long long answer = 0;

	// 全ての順列を探索
	do {
        count = 0;

		count += T[0][p[0]];

		for (int i = 0; i < N-2; i++) {
			count += T[p[i]][p[i+1]];
		}

		count += T[p[N-2]][0];

		if (count == K) {
			answer++;
		}

    } while(next_permutation(p.begin(), p.end()));

	cout << answer << endl;
	return 0;
}