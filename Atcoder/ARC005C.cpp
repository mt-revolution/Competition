#include<bits/stdc++.h>

using namespace std;

int main() {
	int H,W;
	cin >> H >> W;

	vector<vector<char>> c(H, vector<char>(W, '.'));
	// dequeでマスを管理
	deque<pair<int, int>> Q;
	// スタートからそのマスまで壁を最低何回壊して辿り着けるか
	vector<vector<int>> dist(H, vector<int>(W, -1));

    int si,sj,gi,gj;
	
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> c[i][j];
			if (c[i][j] == 's') {
				si = i, sj = j;
			} else if (c[i][j] == 'g') {
                gi = i, gj = j;
            }
		}
	}

	int ui,uj;
	vector<vector<int>> idou = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    // dequeを用いたBFS(道のマスを優先して処理)
    dist[si][sj] = 0;
    Q.push_back(make_pair(si, sj));

	while (Q.empty() == false) {
		tie(ui, uj) = Q.front();
		Q.pop_front();
		
		// 4方向に移動
		for (auto vec : idou) {
			if (ui + vec[0] >= 0 && ui + vec[0] < H && uj + vec[1] >= 0 && uj + vec[1] < W) {
				if (dist[ui + vec[0]][uj + vec[1]] == -1) {
                    // 移動先が壁のときdequeの一番後ろへ
                    if (c[ui + vec[0]][uj + vec[1]] == '#') {
                        dist[ui + vec[0]][uj + vec[1]] = dist[ui][uj] + 1;
                        Q.push_back(make_pair(ui + vec[0], uj + vec[1]));
                    // 移動先が壁以外のときdequeの一番前へ
                    } else {
                        dist[ui + vec[0]][uj + vec[1]] = dist[ui][uj];
                        Q.push_front(make_pair(ui + vec[0], uj + vec[1]));
                    }			
				}
			}
		}
	}

    if (dist[gi][gj] <= 2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

	return 0;
}