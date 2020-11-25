#include<bits/stdc++.h>

using namespace std;

const long long INF = 10000000000000;

int main() {
    long long V,E;
    cin >> V >> E;

    long long s,t,d;
    vector<vector<long long>> graph(V, vector<long long>(V, INF));
    bool flag = false;

    for(int i = 0; i < E; i++) {
        cin >> s >> t >> d;
        graph[s][t] = d;
    }

    for(int i = 0; i < V; i++) {
        graph[i][i] = 0;
    }

    // ワーシャルフロイド法のiからjまで移動するときの最小コストdp[k][i][j]
    vector<vector<long long>> dp(V, vector<long long>(V, INF));

    // 初期条件
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            if(graph[i][j] != INF) {
                dp[i][j] = graph[i][j];
            }
        }
    }

    // dp開始
    for(int k = 0; k < V; k++) {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(dp[i][j] == INF && (dp[i][k] == INF || dp[k][j] == INF)) {
                    dp[i][j] = INF;
                    continue;
                }

                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    // 負の閉路の検出
    for(int i = 0; i < V; i++) {
        if(dp[i][i] < 0) {
            flag = true;
            break;
        }
    }

    if(flag == true) {
        cout << "NEGATIVE CYCLE" << endl;
    } else {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(j > 0) {
                    cout << " ";
                }

                if(dp[i][j] == INF) {
                    cout << "INF";
                    continue;
                }

                cout << dp[i][j];
            }
            cout << endl;
        }
    }

	return 0;
}