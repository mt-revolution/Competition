#include<bits/stdc++.h>

using namespace std;

vector<vector<long long>> A;
int H,W;

// 幅優先探索(二次元迷路の探索)
struct bfs {
    vector<vector<long long>> distance;
	vector<pair<int, int>> delta = {make_pair(1, 0), make_pair(-1, 0), make_pair(0, 1), make_pair(0, -1)};

    bfs(int h, int w) {
        distance.assign(h, vector<long long>(w, 100000000));
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

            // (ui, uj) から上下左右に移動して行ける各マスについて探索
            for (auto v : delta) { 
				if(ui + v.first >= 1 && ui + v.first <= H && uj + v.second >= 1 && uj + v.second <= W) {
					if (distance[ui + v.first][uj + v.second] > distance[ui][uj] + A[ui + v.first][uj + v.second]) {
						distance[ui + v.first][uj + v.second] = distance[ui][uj] + A[ui + v.first][uj + v.second];
						node.push(make_pair(ui + v.first, uj + v.second));
					}
				}
            }           
        }
    }
};

int main() {
	cin >> H >> W;
	
	A.assign(H+2, vector<long long>(W+2));
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			cin >> A[i][j];
		}
	}

	long long answer = 10000000000000;

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			bfs B(H+2, W+2);
			B.do_bfs(i, j);

			answer = min(answer, A[i][j] + B.distance[H][1] + B.distance[H][W] + B.distance[1][W]);
		}
	}

	cout << answer << endl;
	return 0;
}