#include<bits/stdc++.h>

using namespace std;

int main() {
	int N,M;
	cin >> N >> M;
	
	int A;
	int sum = 0;
	for (int i = 0; i < M; i++) {
		cin >> A;
		sum += A;
	}

	if (sum > N) {
		cout << -1 << endl;
	} else {
		cout << N - sum << endl;
	}

	return 0;
}