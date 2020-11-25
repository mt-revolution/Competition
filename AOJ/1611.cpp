#include<bits/stdc++.h>


using namespace std;



int main() {
    int n;
    vector<int> answer;

    while (1) {
        cin >> n;

        if (n == 0) {
            break;
        }

        vector<int> w(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> w[i];
        }

        // [l, r]の範囲で叩き出せるブロック数の最大値dp[l][r]
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        int r;

        // 区間の幅を変える
        for (int width = 1; width < n; width++) {
            // 左端を変える
            for (int l = 1; l <= n; l++) {
                // 右端
                r = l + width;

                if (r > n) {
                    continue;
                }

                // 区間が全て叩き出せる場合
                if (dp[l+1][r-1] == width-1 && abs(w[l] - w[r]) <= 1) {
                    dp[l][r] = width+1;
                }

                // 区間を2つに分けて合計した値と比べて大きい方をとる
                for (int mid = l; mid <= r-1; mid++) {
                    dp[l][r] = max(dp[l][r], dp[l][mid] + dp[mid+1][r]);
                }

            }
        }

        answer.push_back(dp[1][n]);
    }

    for (auto i : answer) {
        cout << i << endl;
    }
	return 0;
}