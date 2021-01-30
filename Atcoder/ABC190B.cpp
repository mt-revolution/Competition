#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
	long long S,D;
	long long answer = 0;

	cin >> N >> S >> D;
	vector<long long> X(N), Y(N);

	for (int i = 0; i < N; i++) {
		cin >> X[i] >> Y[i];
	}
	
	for (int i = 0; i < N; i++) {
		if (X[i] < S && Y[i] > D) {
			cout << "Yes" << endl;
			return 0;
		}
	}

	cout << "No" << endl;
	return 0;
}