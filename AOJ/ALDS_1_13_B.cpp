#include<bits/stdc++.h>

using namespace std;

// 最小値記録用
map<vector<vector<int>>, int> min_move;
// 座標移動用
vector<vector<int>> zahyou = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
// 最終目標
vector<vector<int>> goal = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

// BFSを行う
void do_bfs(vector<vector<int>> A) {
        queue<vector<vector<int>>> node;
        vector<vector<int>> u, v;

        min_move[A] = 0;
        node.push(A);

        int index_i, index_j;

        while (node.empty() == false) {
            u = node.front();
            node.pop();       

            // 0の位置を確認
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (u[i][j] == 0) {
                        index_i = i, index_j = j;
                    }
                }
            }

            // 今の状態からいける全ての状態の組み合わせを調べる
            for (auto combi : zahyou) {
                // 移動可能か判定
                if (index_i + combi[0] >= 0 && index_i + combi[0] < 3 && index_j + combi[1] >= 0 && index_j + combi[1] < 3) {
                    v = u;
                    swap(v[index_i][index_j], v[index_i + combi[0]][index_j + combi[1]]);

                    // 既に値を計算していないか確認
                    if (min_move.find(v) == min_move.end()) {
                        min_move[v] = min_move[u] + 1;
                        node.push(v);

                        // 答えの状態に辿り着いたら終了
                        if (v == goal) {
                            return;
                        }
                    }
                }
            }
             
        }
    }


int main() {
    vector<vector<int>> A(3, vector<int>(3));

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> A[i][j];
        }
    }

    // もともと条件を満たしていたとき
    if (A == goal) {
        cout << 0 << endl;
        return 0;
    }

    do_bfs(A);

    cout << min_move[goal] << endl;  
	return 0;
}