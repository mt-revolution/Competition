#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
	long long D;
	cin >> N >> D;

	vector<long long> X(N), Y(N);
	int count = 0;

	for (int i = 0; i < N; i++) {
		cin >> X[i] >> Y[i];
	}

	for(int i = 0; i < N; i++) {
		if(X[i] * X[i] + Y[i] * Y[i] <= D * D) {
			count++;
		}
	}

	cout << count << endl;
	return 0;
}