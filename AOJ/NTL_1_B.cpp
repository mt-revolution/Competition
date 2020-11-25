#include<bits/stdc++.h>

using namespace std;

// べき乗の余り計算
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}


int main() {
    long long m, n;
    cin >> m >> n;

    cout << modpow(m, n, 1000000007) << endl;
	return 0;
}