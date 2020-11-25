#include<bits/stdc++.h>

using namespace std;

const long long MOD = 2019;

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
	string S;
	cin >> S;
	
	int S_size = S.size();
	
	vector<long long> a(S_size);
	// 各桁の数をMODで割った余りを記録
	for (int i = 0; i < S_size; i++) {
		a[i] = ((S[i]-'0') * modpow(10, S_size - 1 - i, MOD)) % MOD;
	}

	vector<long long> cum_a(S_size+1);
	cum_a[0] = 0;
	
	// aの累積和を記録
	for (int i = 1; i <= S_size; i++) {
		cum_a[i] = (cum_a[i-1] + a[i-1]) % MOD;
	}

	// ソートする
	sort(cum_a.begin(), cum_a.end());

	long long answer = 0;
	long long tmp_num = 99999999, tmp_count = 0;

	// cum_aが同じ値になる2数(i,j)の組み合わせの数を計算して足す
	for (int i = 0; i <= S_size; i++) {
		if (cum_a[i] == tmp_num) {
			tmp_count++;
		} else {
			answer += tmp_count * (tmp_count-1) / 2;
			tmp_num = cum_a[i];
			tmp_count = 1;
		}
	}
	answer += tmp_count * (tmp_count-1) / 2;

	cout << answer << endl;
	return 0;
}