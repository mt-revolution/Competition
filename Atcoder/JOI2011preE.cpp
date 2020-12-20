#include<bits/stdc++.h>

using namespace std;

int main() {
    int H, W, N;
    cin >> H >> W >> N;

    vector<vector<char>> field(H+2, vector<char>(W+2, 'n'));
    vector<vector<int>> distance(H+2, vector<int>(W+2, -1));
    queue<pair<int, int>> checked;
    int start_i, start_j, goal_i, goal_j;
    int y, x;
    int count = 0;

    vector<int> delta_i{-1, 1, 0, 0};
    vector<int> delta_j{0, 0, -1, 1};

    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= W; j++) {
            cin >> field[i][j];

            // スタート地点を0として扱いやすくする
            if(field[i][j] == 'S') {
                field[i][j] = '0';
            }
        }
    }

    vector<pair<int, int>> stop(N+1);

    // 経由地を記録
    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= W; j++) {
            if(field[i][j] >= '0' && field[i][j] <= '9') {
                stop[field[i][j] - '0'] = make_pair(i, j);
            } else if(field[i][j] == 'S') {
                stop[0] = make_pair(i, j);
            }
        }
    }

    // スタートから1、1から2、...、N-1からNまで
    for(int k = 0; k < N; k++) {
        tie(start_i, start_j) = stop[k];
        tie(goal_i, goal_j) = stop[k+1];

        // 初期化
        distance.assign(H+2, vector<int>(W+2, -1));
        checked = {};
        
        // BFS開始
        distance[start_i][start_j] = 0;
        checked.push(pair<int, int>(start_i, start_j));
    
        while(checked.empty() == false) {
            y = checked.front().first;
            x = checked.front().second;
            checked.pop();

            for(int i = 0; i < 4; i++) {                
                if(field[y + delta_j[i]][x + delta_i[i]] != 'n' && field[y + delta_j[i]][x + delta_i[i]] != 'X' && field[y + delta_j[i]][x + delta_i[i]] != '0' + k) {
                    if(distance[y + delta_j[i]][x + delta_i[i]] != -1) {
                        continue;
                    } else {
                        distance[y + delta_j[i]][x + delta_i[i]] = distance[y][x] + 1;
                        checked.push(pair<int, int>(y + delta_j[i], x + delta_i[i]));
                    }
                }
                
            }
        }
        count += distance[goal_i][goal_j];
    }

    cout << count << endl;
	return 0;
}