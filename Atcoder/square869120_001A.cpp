#include<bits/stdc++.h>

using namespace std;


int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<long long>> dist(N, vector<long long>(N, -1));
    vector<vector<long long>> time(N, vector<long long>(N, -1));
    
    int x,y;
    long long z,t;
    const long long INF = 1000000000000000000;

    for(int i = 0; i < M; i++) {
        cin >> x >> y >> z >> t;
        x--, y--;
        dist[x][y] = z;
        dist[y][x] = z;
        time[x][y] = t;
        time[y][x] = t;
    }
    
    // 頂点集合Sのうち最後に訪れる頂点がvである最短閉路の(距離, 数)dp[S][v]
    vector<vector<pair<long long, long long>>> dp((1<<N), vector<pair<long long, long long>>(N, pair<long long, long long>(INF, 0)));

    // 初期条件(頂点0から出発する)
    dp[0][0].first = 0;
    dp[0][0].second = 1;

    // dp開始
    for(int S = 0; S < (1<<N); S++) {
        for(int v = 0; v < N; v++) {
            // jが頂点集合に含まれる場合
            if(S & (1<<v)) {
                // 各頂点uからvに移動するとき
                for(int u = 0; u < N; u++) {
                    // 経路が存在しない、もしくは時間切れで道が通れない場合
                    if(dist[u][v] == -1 || dp[S-(1<<v)][u].first + dist[u][v] > time[u][v]) {
                        continue;
                    }

                    if(dp[S-(1<<v)][u].first + dist[u][v] < dp[S][v].first) {
                        dp[S][v].first = dp[S-(1<<v)][u].first + dist[u][v];
                        dp[S][v].second = 0;
                    }

                    if(dp[S-(1<<v)][u].first + dist[u][v] == dp[S][v].first) {
                        dp[S][v].second += dp[S-(1<<v)][u].second;
                    }
                } 
            }
        }
    }

    if(dp[(1<<N)-1][0].first != INF) {
        cout << dp[(1<<N)-1][0].first << " " << dp[(1<<N)-1][0].second << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}