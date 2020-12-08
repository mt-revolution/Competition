#include<bits/stdc++.h>

using namespace std;

// 移動のパターン
vector<vector<int>> idou = {{1, 1}, {0, 1}, {-1, 1}, {1, 0}, {-1, 0}, {0, -1}};

// 幅優先探索(二次元迷路の探索)
struct Maze {
    vector<vector<vector<pair<int, int>>>> G;
    vector<vector<int>> distance;
	vector<vector<bool>> obstacle;

    Maze(int h, int w) {
        G.assign(h, vector<vector<pair<int, int>>>(w, vector<pair<int, int>>{}));
        distance.assign(h, vector<int>(w, -1));
		obstacle.assign(h, vector<bool>(w, false));
    };

    void do_bfs(int si, int sj) {
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
				if (ui + vec[0] >= 0 && ui + vec[0] <= 402 && uj + vec[1] >= 0 && uj + vec[1] <= 402) {
					if (obstacle[ui + vec[0]][uj + vec[1]] == false) {
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
	int N,X,Y;
	cin >> N >> X >> Y;

    // 座標変換して1<=X,Y<=401で考える、0と402は正方形の外縁
	X += 201, Y += 201;
	
	int x,y;

	Maze Maze(403, 403);

	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		x += 201, y += 201;
		Maze.obstacle[x][y] = true;
	}

    // 始点から幅優先探索
	Maze.do_bfs(201, 201);

	cout << Maze.distance[X][Y] << endl;
	return 0;
}