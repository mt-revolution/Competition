#include<bits/stdc++.h>

using namespace std;

int main() {
	long long N,A,B;
	cin >> N >> A >> B;

	
	if (N <= A) {
		cout << N << endl;
	} else if (N >= A && N <= A+B) {
		cout << A << endl;
	} else {
		long long answer = 0;
		answer += N / (A+B) * A;
		N %= (A+B);
		
		if (N <= A) {
			answer += N;
		} else if (N >= A && N <= A+B) {
			answer += A;
		}
		cout << answer << endl;
	}
	return 0;
}