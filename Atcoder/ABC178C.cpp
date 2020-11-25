#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;

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

// 負の数にも対応した % 演算
long long mod(long long val, long long m) {
    long long res = val % m;
    if (res < 0) {
        res += m;
    }
    
    return res;
}


int main() {
    long long N;
    cin >> N;

    cout << mod(modpow(10, N, MOD) - modpow(9, N, MOD) * 2 + modpow(8, N, MOD), MOD) << endl;
    return 0;
}