#include<bits/stdc++.h>

using namespace std;

// 最大公約数
long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

// 最小公倍数
long long LCM(long long x, long long y) {
	return x * y / GCD(x, y);
}

int main() {
	long long N;
	cin >> N;

	long long tmp = 1;
	
	for (long long i = 2; i <= N; i++) {
		tmp = LCM(tmp, i);
	}

	cout << tmp+1 << endl;
	return 0;
}