#include<bits/stdc++.h>

using namespace std;


int main() {
    int V, E, r;
    cin >> V >> E >> r;
    const int INF = 1000000000;
    
    int s, t, d;
    // 各始点に対しての(終点、重み)の隣接リスト
    vector<vector<pair<int, int>>> length(V, vector<pair<int, int>>{});
    vector<int> dist(V, 0);
    vector<int> prev(V, -1);

    // 優先度付き待ち行列を使って高速化
    priority_queue<pair<int, int>> Q;
    int u;

    for(int i = 0; i < E; i++) {
        cin >> s >> t >> d;
        length[s].push_back(pair<int, int>(t, d));
    }

    // 初期条件
    for(int v = 0; v < V; v++) {
        if(v == r) {
            dist[v] = 0;
        } else {
            dist[v] = INF;
        }

        Q.push(pair<int, int>(dist[v], v));
    }
    
    // ダイクストラ開始
    // Qが空になるまで
    while(Q.empty() == false) {
        // Qの中で一番距離が小さい点uを取り出す
        u = Q.top().second;
        Q.pop();

        // uから行けるvについて処理する
        for(auto v : length[u]) {
            if(dist[v.first] > dist[u] + v.second) {
                dist[v.first] = dist[u] + v.second;
                prev[v.first] = u;
                // 距離の小さい方から取り出すために負にしてQに記録
                Q.push(pair<int, int>(-dist[v.first], v.first));
            }
        }
    }

    for(int i = 0; i < V; i++) {
        if(dist[i] == INF) {
            cout << "INF" << endl;
        } else {
            cout << dist[i] << endl;
        }
    }
	return 0;
}