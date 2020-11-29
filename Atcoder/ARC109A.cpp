#include<bits/stdc++.h>

using namespace std;


// 幅優先探索(最短距離の計算)
struct bfs {
    vector<vector<pair<int, int>>> G;
    vector<int> distance;

    bfs(int N) {
        G.assign(N, vector<pair<int, int>>{});
        distance.assign(N, 1000000000);
    };

    void make_twoedge(int u, int v, int dist) {
        G[u].push_back(make_pair(v, dist));
        G[v].push_back(make_pair(u, dist));
    }

    void do_dijkstra(int s) {
        // 優先度付き待ち行列を使って高速化
		priority_queue<pair<int, int>> Q;
		int u;

		// 初期条件
		for(int v = 1; v <= 200; v++) {
			if(v == s) {
				distance[v] = 0;
			} else {
				distance[v] = 1000000000;
			}

			Q.push(pair<int, int>(distance[v], v));
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
					Q.push(pair<int, int>(-distance[v.first], v.first));
				}
			}
		}
    }
};

int main() {
	int a,b,x,y;
	cin >> a >> b >> x >> y;
	
	bfs tower(201);
	
	for (int i = 1; i < 100; i++) {
		tower.make_twoedge(i, i+1, y);
		tower.make_twoedge(i+1, i+100, x);
	}

	for (int i = 1; i <= 100; i++) {
		tower.make_twoedge(i, i+100, x);
	}

	for (int i = 101; i < 200; i++) {
		tower.make_twoedge(i, i+1, y);
	}

	tower.do_dijkstra(a);

	cout << tower.distance[b+100] << endl;
	return 0;
}