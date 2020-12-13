#include<bits/stdc++.h>

using namespace std;

// 二項係数のmod計算(nが大きいとき)
const long long MOD = 1000000007;

const int MAX = 200001;

vector<long long> fact_inv, inv, Com;

// 初期化
void init_nCk(long long n) {
    fact_inv.resize(MAX);
    inv.resize(MAX);
    fact_inv[0] = fact_inv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        fact_inv[i] = fact_inv[i - 1] * inv[i] % MOD;
    }
    Com.resize(MAX);
    Com[0] = 1;
    for (int i = 1; i < MAX; i++) {
        Com[i] = Com[i - 1] * ((n - i + 1) * inv[i] % MOD) % MOD;
    }
}

/*  nCk :MODでの二項係数を求める(前処理 init_nCk が必要)
    計算量:O(1)
*/
long long nCk(long long k) {
    assert(!(k < 0));
    return Com[k];
}


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
	long long n,a,b;
    cin >> n >> a >> b;
    
    long long answer;

    // 初期化
    init_nCk(n);

    answer = mod(modpow(2, n, MOD) - 1, MOD);
    answer = mod(answer - nCk(a), MOD);
    answer = mod(answer - nCk(b), MOD);
    cout << answer << endl;
	return 0;
}