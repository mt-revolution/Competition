#include<bits/stdc++.h>

using namespace std;

int main() {
	int N,M;
	cin >> N >> M;
	
	int sum = 0, count = 0;
	vector<int> A(N);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
		sum += A[i];
	}

	for (int i = 0; i < N; i++) {
		if (A[i] * 4*M >= sum) {
			count++;
		}
	}

	if (count >= M) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}