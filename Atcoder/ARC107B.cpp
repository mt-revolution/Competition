#include<bits/stdc++.h>

using namespace std;


int main() {
	long long N,K;
	cin >> N >> K;

	long long answer = 0;
	vector<long long> count(2*N+1, 0);

	count[0] = 0, count[1] = 0;
	for (long long i = 2; i <= 2*N; i++) {
		if (i <= N+1) {
			count[i] = count[i-1] + 1;	
		} else {
			count[i] = count[i-1] - 1;	
		}
	}

	for (long long i = 2; i <= 2*N; i++) {
		if (i-K >= 2 && i-K <= 2*N) {
			answer += count[i] * count[i-K];
		}
	}
	
	cout << answer << endl;
	return 0;
}