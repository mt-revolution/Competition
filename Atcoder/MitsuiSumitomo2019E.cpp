#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;

int main() {
    int N;
    cin >> N;

    long long A;

    // 各色の帽子のそれまでの合計
    vector<long long> tmp(3, 0);
    long long count = 1, tmp_count = 0;

    for (int i = 0; i < N; i++) {
        cin >> A;

        tmp_count = 0;
        
        for (int k = 0; k < 3; k++) {
            if (tmp[k] == A) {
                if (tmp_count == 0) {
                    tmp_count += 1;
                    tmp[k] += 1;
                } else {
                    tmp_count += 1;
                }
            }
        }

        count = (count * tmp_count) % MOD;
    }

    cout << count << endl;
	return 0;
}