#include<bits/stdc++.h>

using namespace std;

// 素数判定
bool is_prime(long long N) {
    if(N == 1) {
        return false;
    }

    for (long long a = 2; a * a <= N; a++) {
        if(N % a == 0) {
            return false;
        }
    }

    return true;
}


int main() {
	long long A,B;
    cin >> A >> B;
    
    // 小さい方
    long long small = min(A, B);
    // 大きい方
    long long large = max(A, B);
    long long tmp;

    long long answer = 0;

    // 小さい方の数の約数を全探索
    for (long long i = 1; i*i <= small; i++) {
        if (small % i == 0) {
            tmp = small / i;
            
            // 大きい方の数でも約数か調べる
            if (large % i == 0) {
                // その数が素数であるか調べる
                if (is_prime(i) == true) {
                    answer++;
                }
            }

            // i*i=smallのとき
            if (tmp == i) {
                continue;
            }

            // もう一方の数でも調べる
            if (large % tmp == 0) {
                if (is_prime(tmp) == true) {
                    answer++;
                }
            }
        }
    }

    // 公約数1の分足す
    answer++;

    cout << answer << endl;
	return 0;
}