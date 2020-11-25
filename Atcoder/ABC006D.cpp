#include<bits/stdc++.h>

using namespace std;


int main() {
    int N;
    cin >> N;

    vector<int> c(N);
    int count = 0;
    const int INF = 2000000000;

    for(int i = 0; i < N; i++) {
        cin >> c[i];
    }

    // 最長増加部分列問題の数列の長さがiのときの最終要素の最小値dp[i]
    vector<int> dp(N+1, INF);

    // 初期条件
    dp[1] = c[0];

    // dp開始
    for(int i = 2; i <= N; i++) {
        auto iter = lower_bound(dp.begin()+1, dp.end(), c[i-1]);
        *iter = c[i-1];
    }

    // dp[i]のうちINFではない要素の数が最長増加部分列の項数
    for(int i = 1; i <= N; i++) {
        if(dp[i] == INF) {
            break;
        } else {
            count++;
        }
    }
    
    cout << N - count << endl;
	return 0;
}