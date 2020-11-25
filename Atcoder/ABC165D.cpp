#include<bits/stdc++.h>

using namespace std;

int main() {
	long long A,B,N;
	cin >> A >> B >> N;
	
	long long answer;
	long long x;

	if (B > N) {
		x = N;
	} else {
		x = B-1;
	}

	answer = floor(A*x / B) - A * floor(x / B);

	cout << answer << endl;
	return 0;
}