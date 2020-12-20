#include<bits/stdc++.h>

using namespace std;


void dfs(vector<vector<int>> &G, vector<bool> &seen, vector<int> &closed_node, int s, int u, int prev) {
    seen[u] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : G[u]) { 
        // その1つ前に訪れた点を訪れた場合
        if (next_v == prev) {
            continue;
        }

        // 既に訪れた点に戻ってきた場合(閉路を検出した場合)
        if (seen[next_v] == true) {
            closed_node[s] = 0;
            continue;
        }

        dfs(G, seen, closed_node, s, next_v, u); // 再帰的に探索
    }
}

int main() {
	int N,M;
    cin >> N >> M;
    
    vector<vector<int>> G(N, vector<int>{});
    int u,v;
    
    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<bool> seen(N, false);
    vector<int> closed_node(N, 1);

    int answer = 0;

    for (int i = 0; i < N; i++) {
        if (seen[i] == false) {
            dfs(G, seen, closed_node, i, i, -1);
            answer += closed_node[i];
        }
    }

    cout << answer << endl;
	return 0;
}