#include<bits/stdc++.h>

using namespace std;


struct Graph {
    vector<vector<int>> G;
    vector<int> color;

    Graph(int N) {
        G.assign(N, vector<int>{});
        color.assign(N, -1);
    };

    void make_twoedge(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    }

    void color_change(int s) {
		// sと繋がっているノードの色を変える
		for (auto v : G[s]) { 
			color[v] = color[s];
		}          
    }
};


int main() {
	int N,M,Q;
	cin >> N >> M >> Q;

	Graph Graph(N);
	
	int u,v,c,T,x,y;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		u--, v--;
		Graph.make_twoedge(u, v);
	}

	for (int i = 0; i < N; i++) {
		cin >> c;
		Graph.color[i] = c;
	}

	for (int i = 0; i < Q; i++) {
		cin >> T;
		
		if (T == 1) {
			cin >> x;
			x--;
			cout << Graph.color[x] << endl;
			Graph.color_change(x);
			
		} else {
			cin >> x >> y;
			x--;
			cout << Graph.color[x] << endl;
			Graph.color[x] = y;
		}
	}
	return 0;
}