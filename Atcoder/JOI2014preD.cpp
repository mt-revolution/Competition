#include<bits/stdc++.h>

using namespace std;


int main() {
    int N;
    cin >> N;

    string S;
    cin >> S;

    vector<int> leader(N+1);

    for(int i = 1; i <= N; i++) {
        if(S[i-1] == 'J') {
            leader[i] = 0;
        } else if(S[i-1] == 'O') {
            leader[i] = 1;
        } else {
            leader[i] = 2;
        }
    }

    const long long MOD = 10007;
 
    // i日目に3人の集合Sが参加したときのスケジュールの組み合わせの数を10007で割った余りdp[S][i]
    vector<vector<long long>> dp((1<<3), vector<long long>(N+1, 0));

    // 初期条件
    for(int S = 0; S < (1<<3); S++) {
        if((S & (1<<leader[1])) && (S & (1<<0))) {
            dp[S][1] += 1;
        }     
    }
    
    // dp開始
    for(int i = 2; i <= N; i++) {
        for(int S = 0; S < (1<<3); S++) {
            // 責任者がいるとき
            if(S & (1<<leader[i])) {
                // i-1日目の出席者の集合
                for(int S_prev = 0; S_prev < (1<<3); S_prev++) {
                    // i日目とi-1日目で共通の出席者がいたとき
                    if(S & S_prev) {
                        dp[S][i] = (dp[S][i] + dp[S_prev][i-1]) % MOD;
                    } 
                }         
            }
        }
    }

    long long answer = 0;
    for(int S = 0; S < (1<<3); S++) {
        answer = (answer + dp[S][N]) % MOD;
    }

    cout << answer << endl;
    return 0;
}