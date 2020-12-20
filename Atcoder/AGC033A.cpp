#include<bits/stdc++.h>

using namespace std;

int main() {
	int H,W;
	cin >> H >> W;

	vector<vector<char>> A(H, vector<char>(W, '.'));
	// 黒いマス
	queue<pair<int, int>> black;
	// マスが黒く塗るまでの最小操作回数
	vector<vector<int>> dist(H, vector<int>(W, -1));
	
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> A[i][j];
			if (A[i][j] == '#') {
				dist[i][j] = 0;
				black.push(make_pair(i, j));
			}
		}
	}

	int ui,uj;
	int answer = 0;
	vector<vector<int>> idou = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

	// BFS
	while (black.empty() == false) {
		tie(ui, uj) = black.front();
		black.pop();
		
		// 4方向に移動
		for (auto vec : idou) {
			if (ui + vec[0] >= 0 && ui + vec[0] < H && uj + vec[1] >= 0 && uj + vec[1] < W) {
				// 見ているマスが白のとき
				if (A[ui + vec[0]][uj + vec[1]] != '#') {
					dist[ui + vec[0]][uj + vec[1]] = dist[ui][uj] + 1;
					answer = max(answer, dist[ui + vec[0]][uj + vec[1]]);
					A[ui + vec[0]][uj + vec[1]] = '#';
					black.push(make_pair(ui + vec[0], uj + vec[1]));
				}
			}
		}
	}

	cout << answer << endl;
	return 0;
}