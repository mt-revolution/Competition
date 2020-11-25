#include<bits/stdc++.h>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	vector<int> A(N);

	for(int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for(int i = 1; i <= N-K; i++) {
		if(A[K+i-1] > A[i-1]) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	return 0;
}