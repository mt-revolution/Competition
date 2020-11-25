#include<bits/stdc++.h>

using namespace std;

int main() {
	long long N;
	cin >> N;
	long long A,B;
	long long answer = 0;

	for (int i = 0; i < N; i++) {
		cin >> A >> B;
		answer += (B-A+1)*(B+A)/2;
	}

	cout << answer << endl;
	return 0;
}