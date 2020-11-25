#include<bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    int count = 0;
    const int INF = 2000000000;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // 最長増加部分列問題の数列の長さがiのときの最終要素の最小値dp[i]
    vector<int> dp(n+1, INF);

    // 初期条件
    dp[1] = a[0];


    // dp開始
    for(int i = 2; i <= n; i++) {
        auto iter = lower_bound(dp.begin()+1, dp.end(), a[i-1]);
        *iter = a[i-1];
    }

    for(int i = 1; i <= n; i++) {
        if(dp[i] == INF) {
            break;
        } else {
            count++;
        }
    }
    
    cout << count << endl;
	return 0;
}