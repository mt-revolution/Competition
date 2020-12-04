#include<bits/stdc++.h>

using namespace std;

int n;

// 距離が設定されているグラフに対して様々な処理を実装
struct Graph {
    vector<vector<pair<int, long long>>> G;
    vector<long long> distance;

    Graph(int N) {
        G.assign(N, vector<pair<int, long long>>{});
        distance.assign(N, 1000000000000);
    };

    void make_edge(int u, int v, long long dist) {
        G[u].push_back(make_pair(v, dist));
    }

    void make_twoedge(int u, int v, long long dist) {
        G[u].push_back(make_pair(v, dist));
        G[v].push_back(make_pair(u, dist));
    }

    // ダイクストラ
    void do_dijkstra(int s) {
        // 優先度付き待ち行列を使って高速化
		priority_queue<pair<long long, int>> Q;
		int u;

		// 初期条件
        distance[s] = 0;
		for(int v = 0; v < n; v++) {
			Q.push(pair<long long, int>(distance[v], v));
		}
		
		// ダイクストラ開始
		// Qが空になるまで
		while(Q.empty() == false) {
			// Qの中で一番距離が小さい点uを取り出す
			u = Q.top().second;
			Q.pop();

			// uから行けるvについて処理する
			for(auto v : G[u]) {
				if(distance[v.first] > distance[u] + v.second) {
					distance[v.first] = distance[u] + v.second;
					// 距離の小さい方から取り出すために負にしてQに記録
					Q.push(pair<long long, int>(-distance[v.first], v.first));
				}
			}
		}
    }
};

int main() {
    cin >> n;

    int u, k, v;
    long long c;

    Graph G(n);

    for (int i = 0; i < n; i++) {
        cin >> u >> k;
        
        for (int j = 0; j < k; j++) {
            cin >> v >> c;
            G.make_edge(u, v, c);
        }
    }

    G.do_dijkstra(0);
    
    for (int i = 0; i < n; i++) {
        cout << i << " " << G.distance[i] << endl;
    }
      
    return 0;
}