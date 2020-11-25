#include<bits/stdc++.h>

using namespace std;


int main() {
	int N,M;
	cin >> N >> M;

	vector<long long> w(N);
	vector<long long> l(M), v(M);

	for (int i = 0; i < N; i++) {
		cin >> w[i];
	}

	for (int i = 0; i < M; i++) {
		cin >> l[i] >> v[i];
	}

	
	return 0;
}