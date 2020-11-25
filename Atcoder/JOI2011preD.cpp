#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
    cin >> N;

    vector<int> num(N-1);

    // 左からk個の穴に+か-を入れて、a0からakまでの部分和をBにする方法の数dp[k][B]
    vector<vector<long long>> dp(N-1, vector<long long>(21, 0));
    int answer; 

    for(int i = 0; i < N-1; i++) {
        cin >> num[i];
    }
    cin >> answer;

    // 初期条件
    dp[0][num[0]] = 1;

    // DP開始
    for(int i = 0; i < N-2; i++) {
        for(int j = 0; j <= 20; j++) {
            // +を入れた場合
            if(j - num[i+1] >= 0) {
                dp[i+1][j] += dp[i][j - num[i+1]];
            }
            // -を入れた場合
            if(j + num[i+1] <= 20) {
                dp[i+1][j] += dp[i][j + num[i+1]];
            }
        }
    }

    cout << dp[N-2][answer] << endl;
	return 0;
}