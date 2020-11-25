#include<bits/stdc++.h>

using namespace std;

int main() {
	long long N,K;
	cin >> N >> K;
	
	N = N % K;
	cout << min(N, K-N) << endl;
	return 0;
}