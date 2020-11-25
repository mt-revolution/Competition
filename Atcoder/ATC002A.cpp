#include<bits/stdc++.h>

using namespace std;


int main() {
    int R, C;
    cin >> R >> C;

    int sy, sx, gy, gx;

    cin >> sy >> sx;
    cin >> gy >> gx;

    vector<vector<char>> board(R, vector<char>(C));
    vector<vector<int>> distance(R, vector<int>(C, -1));
    queue<pair<int, int>> checked;
    int y, x;
    vector<int> delta_y{-1, 1, 0, 0};
    vector<int> delta_x{0, 0, -1, 1};

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
                cin >> board.at(i).at(j);
        }
    }

    distance[sy-1][sx-1] = 0;
    checked.push(pair<int, int>(sy-1, sx-1));
    
    while(checked.empty() == false) {
        y = checked.front().first;
        x = checked.front().second;
        checked.pop();

        for(int i = 0; i < 4; i++) {
            if(y + delta_y[i] >= 0 && y + delta_y[i] < R && x + delta_x[i] >= 0 && x + delta_x[i] < C) {
                if(board[y + delta_y[i]][x + delta_x[i]] == '.') {
                    if(distance[y + delta_y[i]][x + delta_x[i]] != -1) {
                        continue;
                    } else {
                        distance[y + delta_y[i]][x + delta_x[i]] = distance[y][x] + 1;
                        checked.push(pair<int, int>(y + delta_y[i], x + delta_x[i]));
                    }
                }
            }
        }
    }

    cout << distance.at(gy-1).at(gx-1) << endl;

	return 0;
}