#include<bits/stdc++.h>

using namespace std;

// 素数判定
bool is_prime(int N) {    
    if(N == 1) {
        return false;
    }

    for (int a = 2; a * a <= N; a++) {
        if(N % a == 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int Q;
    cin >> Q;

    int l, r;
    vector<int> count_like_number(100001, 0);
    vector<int> count(Q, 0);

    count_like_number[0] = 0;

    // 制約の各数について2017likeか判定して数を数える
    for(int i = 1; i <= 100000; i++) {
        if(is_prime(i) == true && is_prime((i+1)/2) == true) {
            count_like_number[i] = count_like_number[i-1] + 1;
        } else {
            count_like_number[i] = count_like_number[i-1];
        }
    }

    // 各クエリについて計算
    for(int k = 0; k < Q; k++) {
        cin >> l >> r;
        count[k] = count_like_number[r] - count_like_number[l-1];
    }

    for(auto c : count) {
        cout << c << endl;
    }

	return 0;
}