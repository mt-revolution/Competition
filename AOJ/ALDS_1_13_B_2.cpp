#include<bits/stdc++.h>

using namespace std;

// 最小値記録用
map<unsigned long long, int> min_move;
// 座標移動用
vector<vector<int>> zahyou = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
// 最終目標
vector<vector<int>> goal = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

// 9の累乗の保存用
vector<unsigned long long> pow9 = {1, 9, 81, 729, 6561, 59049, 531441, 4782969, 43046721};

// ハッシュ値計算
unsigned long long hash_calc(vector<vector<int>> &A) {
    int k = 0;
    unsigned long long h = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            h += (unsigned long long)A[i][j] * pow9[k];
            k++;
        }
    }

    return h;
}

// ハッシュ値復元
vector<vector<int>> hash_restore(unsigned long long hash) {
    vector<vector<int>> A(3, vector<int>(3));

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            A[i][j] = (int)(hash % 9);
            hash /= 9;
        }
    }
    
    return A;
}


// BFSを行う
void do_bfs(vector<vector<int>> A) {
    queue<unsigned long long> node;
    vector<vector<int>> u, v;
    unsigned long long hash_u, hash_v;

    min_move[hash_calc(A)] = 0;
    node.push(hash_calc(A));

    int index_i, index_j;

    while (node.empty() == false) {
        hash_u = node.front();
        node.pop();       
        u = hash_restore(hash_u);

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
                hash_v = hash_calc(v);

                // 既に値を計算していないか確認
                if (min_move.find(hash_v) == min_move.end()) {
                    min_move[hash_v] = min_move[hash_u] + 1;
                    node.push(hash_v);

                    // 答えの状態に辿り着いたら終了
                    if (hash_v == hash_calc(goal)) {
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
    if (hash_calc(A) == hash_calc(goal)) {
        cout << 0 << endl;
        return 0;
    }

    do_bfs(A);

    cout << min_move[hash_calc(goal)] << endl;  
	return 0;
}