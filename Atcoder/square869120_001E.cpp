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
    long long N, Q;
    cin >> N >> Q;

    vector<long long> a(N);
    vector<int> c(Q);
    vector<long long> dist(N), cumu_dist(N);

    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < Q; i++) {
        cin >> c[i];
        c[i]--;
    }

    cumu_dist[0] = 0;

    // 各道路の距離と累積和計算
    for(int i = 1; i < N; i++) {
        dist[i] = modpow(a[i-1], a[i], MOD);
        cumu_dist[i] = (cumu_dist[i-1] + dist[i]) % MOD;
    }

    long long answer = 0;

    // 1から最初に行くところまで
    answer = (answer + cumu_dist[c[0]]) % MOD;

    for(int i = 1; i < Q; i++) {
        answer = (answer + cumu_dist[max(c[i], c[i-1])]) % MOD;
        // 引き算は注意
        answer = mod(answer - cumu_dist[min(c[i], c[i-1])], MOD);
    }

    // 最後に行ったところから1に帰るまで
    answer = (answer + cumu_dist[c[Q-1]]) % MOD;

    cout << answer << endl;
	return 0;
}