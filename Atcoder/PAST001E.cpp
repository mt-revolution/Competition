#include<bits/stdc++.h>

using namespace std;

int main() {
	int N,Q;
	cin >> N >> Q;

	int num,a,b;
	
	vector<vector<int>> graph(N, vector<int>(N, 0));
	vector<vector<int>> graph_tmp;
	for (int i = 0; i < Q; i++) {
		cin >> num;

		if (num == 1) {
			cin >> a >> b;
			a--, b--;

			graph[a][b] = 1;
		} else if (num == 2) {
			cin >> a;
			a--;

			graph_tmp = graph;

			for (int i = 0; i < N; i++) {
				if (graph_tmp[i][a] == 1) {
					graph[a][i] = 1;
				}
			}
		} else if (num == 3) {
			cin >> a;
			a--;

			graph_tmp = graph;

			for (int i = 0; i < N; i++) {
				if (graph_tmp[a][i] == 1) {
					for (int j = 0; j < N; j++) {
						if (j == a) {
							continue;
						}

						if (graph_tmp[i][j] == 1) {
							graph[a][j] = 1;
						}
					}
				}
			}	
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph[i][j] == 1) {
				cout << "Y";
			} else {
				cout << "N";
			}
		}

		cout << endl;
	}
	return 0;
}