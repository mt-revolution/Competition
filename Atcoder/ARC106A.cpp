#include<bits/stdc++.h>

using namespace std;


int main() {
	long long N;
	cin >> N;

	long long A, B;
	long long current_3 = 1;
	long long current_5 = 1;
	bool flag = false;

	for (long long i = 1; current_3 <= N; i++) {
		current_3 *= 3;

		current_5 = 1;
		for (long long j = 1; current_5 <= N; j++) {
			current_5 *= 5;

			if (current_3 + current_5 == N) {
				A = i;
				B = j;
				flag = true;
			}
		}
	}

	if (flag == true) {
		cout << A << " " << B << endl;
	} else {
		cout << -1 << endl;
	}
	return 0;
}