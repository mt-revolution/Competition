#include<bits/stdc++.h>

using namespace std;

int main() {
	int N,K;
	cin >> N >> K;

	int d,a;
	vector<int> id(N, 0);
	for (int i = 0; i < K; i++) {
		cin >> d;

		for (int j = 0; j < d; j++) {
			cin >> a;
			a--;
			id[a] += 1;
		}
	}

	int answer = 0;

	for (int i = 0; i < N; i++) {
		if (id[i] == 0) {
			answer++;
		}
	}

	cout << answer << endl;
	return 0;
}