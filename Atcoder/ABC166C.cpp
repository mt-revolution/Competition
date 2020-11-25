#include<bits/stdc++.h>

using namespace std;

int main() {
	int N,M;
	cin >> N >> M;

	vector<int> H(N);
	for (int i = 0; i < N; i++) {
		cin >> H[i];
	}

	vector<vector<int>> graph(N, vector<int>{});
	int A,B;
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		A--, B--;
		graph[A].push_back(B);
		graph[B].push_back(A);
	}

	bool flag = true;
	int answer = 0;

	for (int i = 0; i < N; i++) {
		flag = true;

		for (auto j : graph[i]) {
			if (H[i] <= H[j]) {
				flag = false;
				break;
			}
		}

		if (flag == true) {
			answer++;
		}
	}

	cout << answer << endl;
	return 0;
}