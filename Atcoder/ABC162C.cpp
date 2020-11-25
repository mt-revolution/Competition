#include<bits/stdc++.h>

using namespace std;

long long gcd(long long x, long long y) {
    if(x % y == 0) {
        return y;
    } else {
        return gcd(y, x % y);
    }
}

int main() {
	long long K;
	cin >> K;
	
	long long answer = 0;

	for (long long i = 1; i <= K; i++) {
		for (long long j = 1; j <= K; j++) {
			for (long long k = 1; k <= K; k++) {
				answer += gcd(i, gcd(j, k));
			}
		}
	}

	cout << answer << endl;
	return 0;
}