#include<bits/stdc++.h>

using namespace std;

const int INF = 1000000000;

int main() {
    int N,K;
    int a,b;

    cin >> N >> K;

    vector<int> C(K+1), R(K+1);
    vector<vector<int>> road(N+1, vector<int>{});

    for(int i = 1; i <= N; i++) {
        cin >> C[i] >> R[i];
    }

    for(int i = 0; i < K; i++) {
        cin >> a >> b;
        road[a].push_back(b);
        road[b].push_back(a);
    }

    vector<int> dist(N+1, -1);
    int v, current;

    // ダイクストラで最小の宿泊費計算
    vector<int> cost(N+1, 0);

    // 優先度付き待ち行列を使って高速化
    priority_queue<pair<int, int>> Q;

    // 初期条件
    for(int v = 1; v <= N; v++) {
        if(v == 1) {
            cost[v] = 0;
        } else {
            cost[v] = INF;
        }

        Q.push(pair<int, int>(cost[v], v));
    }
    
    // ダイクストラ開始
    // Qが空になるまで
    while(Q.empty() == false) {
        // Qの中で一番宿泊費が小さい町currentを取り出す
        current = Q.top().second;
        Q.pop();

        // BFSの初期条件
        queue<int> seen;
        vector<int> reachable;
        dist.assign(N+1, -1);
        dist[current] = 0;
        seen.push(current); 

        // BFS開始
        while (!seen.empty()) {
            v = seen.front();
            seen.pop();

            // v から辿れる頂点をすべて調べる
            for (int u : road[v]) {
                if(dist[u] != -1) {
                    continue;
                }

                if (dist[v] + 1 <= R[current]) {
                    // 新たな頂点 u について距離情報を更新してキューに追加する
                    dist[u] = dist[v] + 1;
                    reachable.push_back(u);
                    seen.push(u);
                }
            }
        }


        // currentから行けるreachableについて処理する
        for(auto v : reachable) {
            if(cost[v] > cost[current] + C[current]) {
                cost[v] = cost[current] + C[current];
                // 宿泊費の小さい方から取り出すために負にしてQに記録
                Q.push(pair<int, int>(-cost[v], v));
            }
        }
    }

    cout << cost[N] << endl;
	return 0;
}