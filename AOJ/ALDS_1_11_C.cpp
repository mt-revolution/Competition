#include<bits/stdc++.h>

using namespace std;

// 幅優先探索(最短距離の計算)
struct bfs {
    vector<vector<int>> G;
    vector<int> distance;

    bfs(int N) {
        G.assign(N, vector<int>{});
        distance.assign(N, -1);
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

        distance[s] = 0;
        node.push(s);

        while (node.empty() == false) {
            u = node.front();
            node.pop();

            // u から行ける各頂点 v について再帰的に探索
            for (auto v : G[u]) { 
                if (distance[v] == -1) {
                    distance[v] = distance[u] + 1;
                    node.push(v);
                }
            }           
        }
    }
};


int main() {
    int n,u,k,v;
    cin >> n;

    bfs B(n+1);

    for (int i = 1; i <= n; i++) {
        cin >> u >> k;

        for (int j = 0; j < k; j++) {
            cin >> v;
            B.make_edge(u, v);
        }
    }

    B.do_bfs(1);

    for (int i = 1; i <= n; i++) {
        cout << i << " " << B.distance[i] << endl;
    }

    return 0;
}