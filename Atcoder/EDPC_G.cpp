#include<bits/stdc++.h>

using namespace std;

struct Graph {
    vector<vector<int>> G;
    vector<int> dp;

    Graph(int N) {
        G.assign(N+1, vector<int>{});
        dp.assign(N+1, -1);
    };

    void make_edge(int u, int v) {
        G[u].push_back(v);
    }

    void make_twoedge(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    }

    // uを始点とする最長経路の長さf(u)
    int f(int u) {
        // dpの値が計算済みのときその値を返す
        if (dp[u] != -1) {
            return dp[u];
        }

        int tmp = 0;
        
        for (auto v : G[u]) {
            tmp = max(tmp, f(v)+1);
        }

        return dp[u] = tmp;
    }
};


int main() {
	int N,M;
    cin >> N >> M;

    int x,y;
    Graph G(N);

    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        G.make_edge(x, y);
    }

    int answer = 0;

    for (int i = 1; i <= N; i++) {
        answer = max(answer, G.f(i));
    }

    cout << answer << endl;
	return 0;
}