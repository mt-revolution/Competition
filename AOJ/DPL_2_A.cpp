#include<bits/stdc++.h>

using namespace std;


int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> dist(V, vector<int>(V, -1));
    int x,y,z;
    const int INF = 10000000;

    for(int i = 0; i < E; i++) {
        cin >> x >> y >> z;
        dist[x][y] = z;
    }
    
    // 頂点集合Sのうち最後に訪れる頂点がjの最短閉路の距離dp[S][j]
    vector<vector<int>> dp((1<<V), vector<int>(V, INF));

    // 初期条件(頂点0から出発する)
    dp[0][0] = 0;

    // dp開始
    for(int S = 0; S < (1<<V); S++) {
        for(int j = 0; j < V; j++) {
            // jが頂点集合に含まれる場合
            if(S & (1<<j)) {
                // 各頂点kからjに移動するとき
                for(int k = 0; k < V; k++) {
                    // 経路が存在しない場合
                    if(dist[k][j] == -1) {
                        continue;
                    }
                    dp[S][j] = min(dp[S][j], dp[S-(1<<j)][k] + dist[k][j]);                    
                } 
            }
        }
    }

    if(dp[(1<<V)-1][0] != INF) {
        cout << dp[(1<<V)-1][0] << endl;
    } else {
        cout << "-1" << endl;
    }

    return 0;
}