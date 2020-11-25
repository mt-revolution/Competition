#include<bits/stdc++.h>

using namespace std;

// 幅優先探索(最短距離の計算)
struct bfs {
    vector<vector<int>> G;
    vector<vector<int>> distance;

    bfs(int N) {
        G.assign(N, vector<int>{});
        distance.assign(N, vector<int>(N, -1));
    };

    void make_twoedge(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    }

    void do_bfs(int s) {
        queue<int> node;
        int u;

        distance[s][s] = 0;
        node.push(s);

        while (node.empty() == false) {
            u = node.front();
            node.pop();

            // u から行ける各頂点 v について再帰的に探索
            for (auto v : G[u]) { 
                if (distance[s][v] == -1) {
                    distance[s][v] = distance[s][u] + 1;
                    node.push(v);
                }
            }           
        }
    }
};

int main() {
	int N,X,Y;
	cin >> N >> X >> Y;
	X--, Y--;

	bfs G(N);
	
	for (int i = 0; i < N-1; i++) {
		G.make_twoedge(i, i+1);
	}

	G.make_twoedge(X, Y);

	// 各点について幅優先探索
	for (int i = 0; i < N; i++) {
		G.do_bfs(i);
	}

	// 距離カウント用
	vector<int> count(N, 0);
	int min_distance;

	// それぞれの点の組み合わせについて計算した距離をカウントする
	for (int i = 0; i < N-1; i++) {
		for (int j = i+1; j < N; j++) {
			min_distance = G.distance[i][j];
			count[min_distance]++;
		}
	}

	for (int i = 1; i < N; i++) {
		cout << count[i] << endl;
	}

	return 0;
}