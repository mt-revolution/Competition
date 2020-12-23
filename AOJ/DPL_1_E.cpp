#include<bits/stdc++.h>

using namespace std;


int main() {
    string s1,s2;
    cin >> s1 >> s2;

    int len_s1 = s1.size(), len_s2 = s2.size();
    
    // s1のi文字目まで、s2のj文字目までを見たときの編集距離dp[i][j]
    vector<vector<int>> dp(len_s1+1, vector<int>(len_s2+1, 1000000000));

    // 初期条件
    dp[0][0] = 0;
    
    for (int i = 1; i <= len_s1; i++) {
        dp[i][0] = i;
    }

    for (int j = 1; j <= len_s2; j++) {
        dp[0][j] = j;
    }

    // dp開始
    for (int i = 1; i <= len_s1; i++) {
        for (int j = 1; j <= len_s2; j++) {
            // s1のi文字目とs2のj文字目が同じとき
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = min({dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1]});
            // s1のi文字目とs2のj文字目が違うとき
            } else {
                dp[i][j] = min({dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + 1});
            }
        }
    }

    cout << dp[len_s1][len_s2] << endl;
	return 0;
}