#include<bits/stdc++.h>

using namespace std;


int main() {
    int R, C;
    cin >> R >> C;

    int sy, sx, gy, gx;

    cin >> sy >> sx;
    cin >> gy >> gx;

    vector<vector<char>> board(R+2, vector<char>(C+2));
    vector<vector<int>> distance(R+2, vector<int>(C+2, -1));
    queue<pair<int, int>> checked;
    int y, x;
    vector<int> delta_y{-1, 1, 0, 0};
    vector<int> delta_x{0, 0, -1, 1};

    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            cin >> board.at(i).at(j);
        }
    }

    distance[sy][sx] = 0;
    checked.push(pair<int, int>(sy, sx));
    
    while(checked.empty() == false) {
        y = checked.front().first;
        x = checked.front().second;
        checked.pop();

        for(int i = 0; i < 4; i++) {
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

    cout << distance.at(gy).at(gx) << endl;
	return 0;
}