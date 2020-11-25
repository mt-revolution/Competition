#include<bits/stdc++.h>

using namespace std;

int main() {
	long long X;
	cin >> X;

	long long A,B;

	for (long long i = -1000; i <= 1000; i++) {
		for (long long j = -1000; j <= 1000; j++) {
			if (i*i*i*i*i - j*j*j*j*j == X) {
				A = i, B = j;
				break;
			}
		}
	}

	cout << A << " " << B << endl;
	return 0;
}