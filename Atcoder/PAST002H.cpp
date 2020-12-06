// Not Completed

#include<bits/stdc++.h>

using namespace std;


int main() {
	int N,M;
	cin >> N >> M;
	
	vector<vector<char>> board(N, vector<char>(M, '.'));

	vector<vector<int>> move = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

	int si, sj, gi, gj;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];

			if (board[i][j] == 'S') {
				si = i, sj = j;
			}
		}
	}

	vector<char> destination = {'1', '2', '3', '4', '5', '6', '7', '8', '9', 'G'};

	int answer = 0;
	bool flag;

	for (int k = 0; k < 10; k++) {
		queue<pair<int, int>> node;
		vector<vector<int>> distance(N, vector<int>(M, -1));
		int ui, uj;

		distance[si][sj] = 0;
		node.push(make_pair(si, sj));
		flag = false;

		while (node.empty() == false) {
			ui = node.front().first;
			uj = node.front().second;
			node.pop();

			// (ui, uj) から行ける各マス (vi, vj) について再帰的に探索
			for (auto v : move) { 
				if (ui + v[0] >= 0 && ui + v[0] < N && uj + v[1] >= 0 && uj + v[1] < M) {
					if (distance[ui + v[0]][uj + v[1]] == -1) {
						distance[ui + v[0]][uj + v[1]] = distance[ui][uj] + 1;
						node.push(make_pair(ui + v[0], uj + v[1]));

						if (board[ui + v[0]][uj + v[1]] == destination[k]) {
							si = ui + v[0], sj = uj + v[1];
							answer += distance[ui + v[0]][uj + v[1]];
							flag = true;
							break;
						}
					}
					
				}
			}   

			if (flag == true) {
				break;
			}        
		}

		if (flag == false) {
			cout << -1 << endl;
			return 0;
		}
	}
	
	cout << answer << endl;
	return 0;
}