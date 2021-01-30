#include<bits/stdc++.h>

using namespace std;

int main() {
	int N,M;
	cin >> N >> M;
	
	vector<int> A(M), B(M);
	for (int i = 0; i < M; i++) {
		cin >> A[i] >> B[i];
	}

	int K;
	cin >> K;

	vector<int> C(K), D(K);
	for (int i = 0; i < K; i++) {
		cin >> C[i] >> D[i];
	}

	int answer = 0;
	int count;

	// bit全探索(右からi桁目が1:C[i]にボールを置く 0:D[i]にボールを置く)
	for (int bit = 0; bit < (1<<K); bit++) {
		count = 0;
		vector<int> id(N+1, 0);

		for (int i = 0; i < K; i++) {
			if (bit & (1<<i)) {
				id[C[i]] = 1;
			} else {
				id[D[i]] = 1;
			}
		}

		for (int i = 0; i < M; i++) {
			if (id[A[i]] == 1 && id[B[i]] == 1) {
				count++;
			}
		}

		answer = max(answer, count);
	}

	cout << answer << endl;
	return 0;
}