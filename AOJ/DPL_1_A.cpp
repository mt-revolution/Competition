#include<bits/stdc++.h>

using namespace std;


int main() {
    int q;
    cin >> q;

    vector<string> X(q), Y(q);
    int X_size, Y_size;

    // vector<int> tmp(3, 0);

    for(int i = 0; i < q; i++) {
        cin >> X[i];
        cin >> Y[i];
    }

    for(int k = 0; k < q; k++) {
        X_size = X[k].size();
        Y_size = Y[k].size();

        // Xのi文字目までとTのj文字目までのLCSの長さdp[i][j]
        vector<vector<int> > dp(X_size+1, vector<int>(Y_size+1, 0));

        // 初期条件
        dp[1][0] = 0, dp[0][1] = 0;

        // dp開始
        for(int i = 1; i <= X_size; i++) {
            for(int j = 1; j <= Y_size; j++) {
                if(X[k][i-1] == Y[k][j-1]) {
                    // tmp = {};
                    // tmp.push_back(dp[i-1][j-1] + 1);
                    // tmp.push_back(dp[i-1][j]);
                    // tmp.push_back(dp[i][j-1]);
                    // sort(tmp.begin(), tmp.end());
                    // dp[i][j] = tmp.back();
                    dp[i][j] = max({dp[i-1][j-1] + 1, dp[i-1][j], dp[i][j-1]});
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        cout << dp[X_size][Y_size] << endl;
    }

	return 0;
}