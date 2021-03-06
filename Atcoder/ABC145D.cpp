#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;

const int MAX = 200001;

vector<long long> fac(MAX), finv(MAX), inv(MAX);

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k || n < 0 || k < 0) {
        return 0;
    }
    
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


int main() {
    int n, k;
    cin >> n >> k;

    COMinit();
    
    // 重複する数を考えると、n+k-1個の中からk個選んで数を配置した組み合わせの場合の数が答え
    cout << COM((n+k)-1, k) << endl;
	return 0;
}