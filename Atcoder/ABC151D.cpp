#include<bits/stdc++.h>

using namespace std;

// 幅優先探索(二次元迷路の探索)
// 移動のパターン
vector<vector<int>> idou = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int H,W;

struct Maze {
    vector<vector<int>> distance;
    vector<vector<char>> board;
    // 障害物の文字設定
    char obstacle = '#';

    Maze(int h, int w) {
        board.assign(h, vector<char>(w, 'E'));
        distance.assign(h, vector<int>(w, -1));
    };

    void do_bfs(int si, int sj) {
        // 始点が障害物なら何もしない
        if (board[si][sj] == obstacle) {
            return;
        }

        queue<pair<int, int>> node;
        int ui, uj;

        distance[si][sj] = 0;
        node.push(make_pair(si, sj));

        while (node.empty() == false) {
            ui = node.front().first;
            uj = node.front().second;
            node.pop();

            // (ui, uj) から行ける各マス (vi, vj) について再帰的に探索
            for (auto vec : idou) { 
                // 移動先がグリッドの範囲内かつ障害物がなくかつ距離をまだ計算していない場合に更新
				if (ui + vec[0] >= 0 && ui + vec[0] < H && uj + vec[1] >= 0 && uj + vec[1] < W) {
					if (board[ui + vec[0]][uj + vec[1]] != obstacle) {
						if (distance[ui + vec[0]][uj + vec[1]] == -1) {
							distance[ui + vec[0]][uj + vec[1]] = distance[ui][uj] + 1;
							node.push(make_pair(ui + vec[0], uj + vec[1]));
						}			
					}	
				}
            }           
        }
    }
};

int main() {
    cin >> H >> W;
    
    Maze Maze(H, W);
    
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> Maze.board[i][j];
        }
    }

    int answer = 0;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            Maze.distance.assign(H, vector<int>(W, -1));

            Maze.do_bfs(i, j);
            
            for (int k = 0; k < H; k++) {
                for (int l = 0; l < W; l++) {
                    answer = max(answer, Maze.distance[k][l]);
                }
            }
        }
    }
    
    cout << answer << endl;
	return 0;
}