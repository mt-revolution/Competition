#include<bits/stdc++.h>

using namespace std;


int main() {
	int N,K;
    cin >> N >> K;

    vector<int> a(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    // 両者最適な操作をする場合に残りの石がi個のときに石を選択する者が勝つかどうか(0:負け 1:勝ち)dp[i]
    vector<int> dp(K+1, -1);

    // 初期条件
    dp[0] = 0;

    for (int i = 1; i <= K; i++) {
        // それぞれの石を選んだ時
        for (int j = 1; j <= N; j++) {
            dp[i] = 0;

            if (i-a[j] >= 0) {
                // 負けの局面が存在したとき
                if (dp[i-a[j]] == 0) {
                    dp[i] = 1;
                    break;
                }
            }
        }   
    }

    if (dp[K] == 1) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }
	return 0;
}