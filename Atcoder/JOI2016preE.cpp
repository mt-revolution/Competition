#include<bits/stdc++.h>

using namespace std;

const long long INF = 1000000000000000;

int main() {
    int N,M,K,S;
    int P,Q;
    int a,b,c;

    cin >> N >> M >> K >> S;
    cin >> P >> Q;

    vector<int> C(K);
    vector<vector<int>> road(N+1, vector<int>{});

    for(int i = 0; i < K; i++) {
        cin >> c;
        C[i] = c;
    }

    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        road[a].push_back(b);
        road[b].push_back(a);
    }

    vector<bool> dangerous(N+1, false);
    vector<int> dist(N+1, -1);
    vector<int> expense(N+1, P);
    int v;

    // 危険な町の判定
    // 全ての危険な町に繋がる架空の町0を追加して点0から探索する
    for(auto i : C) {
        road[0].push_back(i);
    }

    // BFSの初期条件(町0を初期ノードとする)
    queue<int> seen;
    dist[0] = 0;
    dangerous[0] = true;
    seen.push(0); 

    // BFS開始
    while (!seen.empty()) {
        v = seen.front();
        seen.pop();

        // v から辿れる頂点をすべて調べる
        for (int u : road[v]) {
            if(u == 0 || dangerous[u] == true) {
                continue;
            }

            if (dist[v] + 1 <= S+1) {
                // 新たな頂点 u について距離情報を更新してキューに追加する
                dist[u] = dist[v] + 1;
                dangerous[u] = true;
                seen.push(u);
            }
        }
    }

    // 架空の町0を削除
    for(auto i : C) {
        road[i].pop_back();
    }
    
    // 各町の宿泊費を計算
    for(int i = 1; i <= N; i++) {
        if(i == 1 || i == N) {
            expense[i] = 0;
            continue;
        }

        if(dangerous[i] == true) {
            expense[i] = Q;
        }
    }

    // ゾンビに支配された町にフラグを付ける
    for(auto i : C) {
        expense[i] = -1;
    }

    // ダイクストラで最小の宿泊費計算
    vector<long long> cost(N+1, 0);
    vector<vector<pair<int, long long>>> length(N+1, vector<pair<int, long long>>{});

    // 優先度付き待ち行列を使って高速化
    priority_queue<pair<long long, int>> queue;

    for(int i = 1; i <= N; i++) {
        for(auto v : road[i]) {
            // ゾンビに支配された町は除外
            if(expense[v] == -1) {
                continue;
            }

            length[i].push_back(pair<int, long long>(v, expense[v]));
        }
    }

    // 初期条件
    for(int v = 1; v <= N; v++) {
        if(v == 1) {
            cost[v] = 0;
        } else {
            cost[v] = INF;
        }

        queue.push(pair<long long, int>(cost[v], v));
    }
    
    // ダイクストラ開始
    // queueが空になるまで
    while(queue.empty() == false) {
        // queueの中で一番宿泊費が小さい町uを取り出す
        int u = queue.top().second;
        queue.pop();

        // uから行けるvについて処理する
        for(auto v : length[u]) {
            if(cost[v.first] > cost[u] + v.second) {
                cost[v.first] = cost[u] + v.second;
                // 宿泊費の小さい方から取り出すために負にしてQに記録
                queue.push(pair<int, int>(-cost[v.first], v.first));
            }
        }
    }

    cout << cost[N] << endl;
	return 0;
}