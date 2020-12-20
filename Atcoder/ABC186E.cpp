#include<bits/stdc++.h>

using namespace std;

// 負の数にも対応した % 演算
long long mod(long long val, long long m) {
    long long res = val % m;
    if (res < 0) {
        res += m;
    }
    
    return res;
}


// mod. m での a の逆元 a^{-1} を計算する
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}


// 最大公約数
long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

int main() {
	int T;
	cin >> T;
	
	long long N,S,K;
	long long x;
	long long d;

	for (int i = 0; i < T; i++) {
		cin >> N >> S >> K;

		// K, S, Nの最大公約数を求めて各数をそれで割る
		d = GCD(GCD(K, S), N);
		N /= d, S /= d, K /= d;
		
		// 残ったK,Nの商の最大公約数が1のとき
		if (GCD(K, N) == 1) {
			x = mod(-modinv(K, N) * S, N);
			cout << x << endl;
		} else {
			cout << -1 << endl;
		}
	}

	return 0;
}