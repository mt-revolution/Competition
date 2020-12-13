#include<bits/stdc++.h>

using namespace std;


int main() {
    long long N;
    cin >> N;
    
    long long N_tmp = N;
    // 5が何個含まれているか
    long long count_5 = 0;
    
    // Nが奇数のとき
    if (N % 2 == 1) {
        cout << 0 << endl;
    // Nが偶数のとき、N/2に5が何個含まれているか調べる
    } else {
        N_tmp = N/2;

        while (N_tmp != 0) {
            count_5 += N_tmp/5;
            N_tmp /= 5;
        }

        cout << count_5 << endl;
    }
	return 0;
}