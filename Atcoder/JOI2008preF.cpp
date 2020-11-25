#include<bits/stdc++.h>

using namespace std;


int main() {
    int n, k;
    cin >> n >> k;
    const int INF = 1000000000;
    
    int number, a, b, c;
    // 各始点に対しての(終点、重み)の隣接リスト
    vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>{});
    vector<int> cost(n, 0);
    vector<int> prev(n, -1);
    vector<int> answer;

    // 優先度付き待ち行列を使って高速化
    priority_queue<pair<int, int>> Q;
    int u;

    for(int i = 0; i < k; i++) {
        cin >> number;

        // 船舶の追加
        if(number == 1) {
            cin >> a >> b >> c;
            a--, b--;
            graph[a].push_back(pair<int, int>(b, c));
            graph[b].push_back(pair<int, int>(a, c));

        // 客の注文
        } else {
            cin >> a >> b;
            a--, b--;

            // 初期化
            priority_queue<pair<int, int>> Q;
            cost.assign(n, 0);
            prev.assign(n, 0);

            // 初期条件
            for(int v = 0; v < n; v++) {
                if(v == a) {
                    cost[v] = 0;
                } else {
                    cost[v] = INF;
                }

                Q.push(pair<int, int>(cost[v], v));
            }
            
            // ダイクストラ開始
            // Qが空になるまで
            while(Q.empty() == false) {
                // Qの中で一番コストが小さい点uを取り出す
                u = Q.top().second;
                Q.pop();

                // uから行けるvについて処理する
                for(auto v : graph[u]) {
                    if(cost[v.first] > cost[u] + v.second) {
                        cost[v.first] = cost[u] + v.second;
                        prev[v.first] = u;
                        // コストの小さい方から取り出すために負にしてQに記録
                        Q.push(pair<int, int>(-cost[v.first], v.first));
                    }
                }
            }

            // 結果の記録
            if(cost[b] == INF) {
                answer.push_back(-1);
            } else {
                answer.push_back(cost[b]);
            }
        }                
    }

    // 結果の出力
    for(auto i : answer) {
        cout << i << endl;
    }
	return 0;
}