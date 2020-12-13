#include<bits/stdc++.h>

using namespace std;


int main() {
    int N;
	cin >> N;
	
	vector<pair<int, int>> edge(N);
	vector<vector<int>> G(N, vector<int>{});
	int a,b;

	for (int i = 0; i < N-1; i++) {
		cin >> a >> b;
		a--, b--;
		edge[i] = make_pair(a, b);
		G[a].push_back(b);
		G[b].push_back(a);
	}

	int K = 0, color_tmp;

	queue<int> node;
	// その点の探索が終わっているか記録
	vector<bool> seen(N, false);
	// その点の親との辺の色
	vector<int> color_parent(N, 0);
	// 辺と色の関係
	map<pair<int, int>, int> color;
	int u;

	// ノード0からBFS開始
	seen[0] = true;
	node.push(0);

	while (node.empty() == false) {
		u = node.front();
		node.pop();
		color_tmp = 1;

		// u から行ける各頂点 v について再帰的に探索
		for (auto v : G[u]) { 
			// Kの更新
			K = max(K, (int)G[u].size());

			// 点の探索が終わっていないとき
			if (seen[v] == false) {
				// 色が既に親との辺で使われていたとき
				if (color_tmp == color_parent[u]) {
					color_tmp++;
				}

				color[make_pair(u, v)] = color_tmp;
				color[make_pair(v, u)] = color_tmp;
				color_parent[v] = color_tmp;
				color_tmp++;
				node.push(v);
			}
		} 

		seen[u] = true;          
	}
	
	cout << K << endl;

	for (int i = 0; i < N-1; i++) {
		cout << color[edge[i]] << endl;
	}

	return 0;
}