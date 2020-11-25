#include<bits/stdc++.h>

using namespace std;

const int INF = 1000000000;

int main() {
    int N,M;
    cin >> N >> M;

    int a,b,t;
    vector<vector<int>> graph(N, vector<int>(N, INF));

    for(int i = 0; i < M; i++) {
        cin >> a >> b >> t;
        a--, b--;
        graph[a][b] = t;
        graph[b][a] = t;
    }

    for(int i = 0; i < N; i++) {
        graph[i][i] = 0;
    }

    // ワーシャルフロイド法におけるiからjまで移動するときの最小コストdp[k][i][j]
    vector<vector<int>> dp(N, vector<int>(N, INF));

    // 初期条件
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(graph[i][j] != INF) {
                dp[i][j] = graph[i][j];
            }
        }
    }

    // dp開始
    for(int k = 0; k < N; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    int tmp = 0, answer = INF;

    // 各バス停からの最も時間が長くなる経路を比べて一番短い出発地点を選ぶ
    for(int i = 0; i < N; i++) {
        tmp = 0;
        for(int j = 0; j < N; j++) {
            tmp = max(tmp, dp[i][j]);
        }

        answer = min(answer, tmp);
    }   

    cout << answer << endl;
	return 0;
}