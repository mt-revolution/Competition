#include<bits/stdc++.h>

using namespace std;

long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}


int main() {
	int N;
	cin >> N;

	vector<long long> a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	long long answer = a[0];

	for (int i = 0; i < N; i++) {
		answer = GCD(answer, a[i]);
	}

	cout << answer << endl;
	return 0;
}