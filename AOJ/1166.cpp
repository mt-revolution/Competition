#include<bits/stdc++.h>

using namespace std;

// 幅優先探索(二次元迷路の探索)
struct bfs {
    vector<vector<vector<pair<int, int>>>> G;
    vector<vector<int>> distance;

    bfs(int h, int w) {
        G.assign(h, vector<vector<pair<int, int>>>(w, vector<pair<int, int>>{}));
        distance.assign(h, vector<int>(w, 0));
    };

    void make_edge(int ui, int uj, int vi, int vj) {
        G[ui][uj].push_back(make_pair(vi, vj));
    }

    void make_twoedge(int ui, int uj, int vi, int vj) {
        G[ui][uj].push_back(make_pair(vi, vj));
        G[vi][vj].push_back(make_pair(ui, uj));
    }

    void do_bfs(int si, int sj) {
        queue<pair<int, int>> node;
        int ui, uj;

        distance[si][sj] = 1;
        node.push(make_pair(si, sj));

        while (node.empty() == false) {
            ui = node.front().first;
            uj = node.front().second;
            node.pop();

            // (ui, uj) から行ける各マス (vi, vj) について再帰的に探索
            for (auto v : G[ui][uj]) { 
                if (distance[v.first][v.second] == 0) {
                    distance[v.first][v.second] = distance[ui][uj] + 1;
                    node.push(v);
                }
            }           
        }
    }
};


int main() {
    int w,h;

    while (1) {
        cin >> w >> h;

        if (w == 0 && h == 0) {
            break;
        }

        vector<vector<int>> vertical(h+1, vector<int>(w, 0));
        vector<vector<int>> horizontal(h, vector<int>(w+1, 0));

        for (int i = 1; i <= h-1; i++) {
            for (int j = 1; j <= w-1; j++) {
                cin >> vertical[i][j];
            }

            for (int j = 1; j <= w; j++) {
                cin >> horizontal[i][j];
            }
        }

        for (int j = 1; j <= w-1; j++) {
            cin >> vertical[h][j];
        }

        bfs B(h+2, w+2);

        // 垂直方向の壁を検出、壁がなければ繋ぐ
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w-1; j++) {
                if (vertical[i][j] == 0) {
                    B.make_twoedge(i, j, i, j+1);
                }
            }
        }

        // 水平方向の壁を検出、壁がなければ繋ぐ
        for (int i = 1; i <= h-1; i++) {
            for (int j = 1; j <= w; j++) {
                if (horizontal[i][j] == 0) {
                    B.make_twoedge(i, j, i+1, j);
                }
            }
        }

        B.do_bfs(1, 1);

        cout << B.distance[h][w] << endl;     
    }

    return 0;
}