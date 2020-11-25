#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	vector<int> GCD_degree(1001, 0);

	for (int i = 0; i < N; i++) {
		for (int k = 2; k <= 1000; k++) {
			if (A[i] % k == 0) {
				GCD_degree[k] += 1;
			}
		}
	}

	int answer;
	int max_degree = 0;

	for (int k = 2; k <= 1000; k++) {
		if (max_degree < GCD_degree[k]) {
			answer = k;
			max_degree = GCD_degree[k];
		}
	}

	cout << answer << endl;
	return 0;
}