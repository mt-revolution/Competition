#include<bits/stdc++.h>

using namespace std;

// 幅優先探索(最短距離の計算)
struct bfs {
    vector<vector<int>> G;
    vector<int> mark;

    bfs(int N) {
        G.assign(N, vector<int>{});
        mark.assign(N, -1);
    };

    void make_edge(int u, int v) {
        G[u].push_back(v);
    }

    void make_twoedge(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    }

    void do_bfs(int s) {
        queue<int> node;
        int u;

        mark[s] = 0;
        node.push(s);

        while (node.empty() == false) {
            u = node.front();
            node.pop();

            // u から行ける各頂点 v について再帰的に探索
            for (auto v : G[u]) { 
                if (mark[v] == -1) {
                    mark[v] = u;
                    node.push(v);
                }
            }           
        }
    }
};

int main() {
	int N,M;
    cin >> N >> M;

    int A,B;

    bfs Graph(N+1);

    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        Graph.make_twoedge(A, B);
    }

    Graph.do_bfs(1);

    cout << "Yes" << endl;
    for (int i = 2; i <= N; i++) {
        cout << Graph.mark[i] << endl;
    }
	return 0;
}