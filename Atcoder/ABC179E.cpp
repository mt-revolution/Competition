#include<bits/stdc++.h>

using namespace std;

const long long MOD = 998244353;

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
    long long N,X,M;
    cin >> N >> X >> M;

    vector<long long> A;
    vector<int> id(M, -1);
    int len = 0;
    long long sum = 0;
    
    while (id[X] == -1) {
        A.push_back(X);
        id[X] = len;
        len++;
        sum += X;
        X = modpow(X, 2, M);
    }

    int loop = len - id[X];
    long long loop_sum = 0;

    for (int i = id[X]; i < len; i++) {
        loop_sum += A[i];
    }

    long long answer = 0;

    if (N <= len) {
        for (int i = 0; i < N; i++) {
            answer += A[i];
        }

    } else {
        answer += sum;
        N -= len;
        answer += loop_sum * (N/loop);
        N %= loop;
        for (int i = 0; i < N; i++) {
            answer += A[id[X] + i];
        }
    }

    cout << answer << endl;
    return 0;
}