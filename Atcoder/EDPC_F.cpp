#include<bits/stdc++.h>

using namespace std;

int main() {
	string s,t;
    cin >> s;
    cin >> t;

    int s_size = s.size(), t_size = t.size();

    // インデックス0にダミー文字を挿入して、文字列をインデックス1から始めて扱いやすくする
    s.insert(0, "#");
    t.insert(0, "#");
    
    // sのi文字目までとtのj文字目までの共通部分文字列の最大の大きさdp[i][j]
    vector<vector<int>> dp(s_size + 1, vector<int>(t_size + 1, 0));

    // 初期条件
    dp[0][1] = 0, dp[1][0] = 0;

    // dp開始
    for (int i = 1; i <= s_size; i++) {
        for (int j = 1; j <= t_size; j++) {
            // sのi文字目とtのj文字目が同じ文字のとき
            if (s[i] == t[j]) {
                dp[i][j] = max({dp[i-1][j-1] + 1, dp[i-1][j], dp[i][j-1]});
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    string answer = "";
    int i = s_size, j = t_size;

    // 逆にたどって答えの文字列を作る
    while (i >= 1 && j >= 1) {
        if (dp[i][j] == dp[i-1][j]) {
            i--;
        } else if (dp[i][j] == dp[i][j-1]) {
            j--;
        } else {
            answer = s[i] + answer;
            i--, j--;
        }
    }

    cout << answer << endl;
	return 0;
}