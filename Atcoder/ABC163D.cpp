#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;

int main() {
	long long N,K;
	cin >> N >> K;

	long long answer = 0;
	
	// i=K,K+1,...,N+1のそれぞれについて和がいくつ出来るのかを計算して足す
	for (long long i = K; i <= N+1; i++) {
		answer = (answer + i*N-i*i+i+1) % MOD;
	}

	cout << answer << endl;
	return 0;
}