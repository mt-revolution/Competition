#include<bits/stdc++.h>

using namespace std;

int main() {
	int H, W;

	vector<int> move_delta_x = {-1, 1, 0, 0};
	vector<int> move_delta_y = {0, 0, -1, 1};
	vector<int> warp_delta_x = {-2, -2, -2, -2, -2, -1, -1, -1, -1, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 2};
	vector<int> warp_delta_y = {2, 1, 0, -1, -2, 2, 1, -1, -2, 2, -2, 2, 1, -1, -2, 2, 1, 0, -1, -2};

	int Ch,Cw,Dh,Dw;
	cin >> H >> W;
	cin >> Ch >> Cw;
	cin >> Dh >> Dw;
	Ch--, Cw--, Dh--, Dw--;


	vector<vector<char>> board(H, vector<char>(W));
	vector<vector<int>> cost(H, vector<int>(W, -1));
	queue<pair<int, int>> checked_move;
	queue<pair<int, int>> checked_warp;
	int y, x;


	for(int i = 0; i < H; i++) {
		for(int j = 0; j < W; j++) {
			cin >> board[i][j];
		}
	}

	cost[Ch][Cw] = 0;
	checked_move.push(pair<int, int>(Ch, Cw));
	checked_warp.push(pair<int, int>(Ch, Cw));	

	while(checked_move.empty() == false || checked_warp.empty() == false) {
		if(checked_move.empty() == false) {
			y = checked_move.front().first;
			x = checked_move.front().second;
			checked_move.pop();

			for(int i = 0; i < 4; i++) {
				if(y + move_delta_y[i] >= 0 && y + move_delta_y[i] < H && x + move_delta_x[i] >= 0 && x + move_delta_x[i] < W) {
					if(board[y + move_delta_y[i]][x + move_delta_x[i]] == '.') {
						if(cost[y + move_delta_y[i]][x + move_delta_x[i]] != -1) {
							continue;
						} else {
							cost[y + move_delta_y[i]][x + move_delta_x[i]] = cost[y][x];
							checked_move.push(pair<int, int>(y + move_delta_y[i], x + move_delta_x[i]));
							checked_warp.push(pair<int, int>(y + move_delta_y[i], x + move_delta_x[i]));
						}
					}
				}
			}
		} else {
			y = checked_warp.front().first;
			x = checked_warp.front().second;
			checked_warp.pop();

			for(int i = 0; i < 20; i++) {
				if(y + warp_delta_y[i] >= 0 && y + warp_delta_y[i] < H && x + warp_delta_x[i] >= 0 && x + warp_delta_x[i] < W) {
					if(board[y + warp_delta_y[i]][x + warp_delta_x[i]] == '.') {
						if(cost[y + warp_delta_y[i]][x + warp_delta_x[i]] != -1) {
							continue;
						} else {
							cost[y + warp_delta_y[i]][x + warp_delta_x[i]] = cost[y][x] + 1;
							checked_move.push(pair<int, int>(y + warp_delta_y[i], x + warp_delta_x[i]));
							checked_warp.push(pair<int, int>(y + warp_delta_y[i], x + warp_delta_x[i]));
						}
					}
				}
			}
		}
	}
	

	cout << cost[Dh][Dw] << endl;
	return 0;
}

