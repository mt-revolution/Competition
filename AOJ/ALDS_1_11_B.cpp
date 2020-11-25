#include<bits/stdc++.h>

using namespace std;

// 深さ優先探索
struct dfs {
    vector<vector<int>> G;
    vector<int> d;
    vector<int> f;
    int t;

    dfs(int N) {
        G.assign(N, vector<int>{});
        d.assign(N, 0);
        f.assign(N, 0);
        t = 1;
    };

    void make_edge(int u, int v) {
        G[u].push_back(v);
    }

    void make_twoedge(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    }

    void do_dfs(int u) {
        d[u] = t;
        t++;

        // u から行ける各頂点 v について再帰的に探索
        for (auto v : G[u]) { 
            if (d[v] != 0) {
                continue;
            }

            do_dfs(v);

        }

        f[u] = t;
        t++;
    }
};


int main() {
    int n,u,k,v;
    cin >> n;

    dfs D(n+1);

    for (int i = 1; i <= n; i++) {
        cin >> u >> k;

        for (int j = 0; j < k; j++) {
            cin >> v;
            D.make_edge(u, v);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (D.d[i] == 0) {
            D.do_dfs(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << i << " " << D.d[i] << " " << D.f[i] << endl;
    }

    return 0;
}