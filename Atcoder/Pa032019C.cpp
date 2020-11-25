#include<bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    int64_t point = 0;
    int64_t max_point = 0;

    cin >> N >> M;

    vector<vector<int>> A(N, vector<int>(M));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }

    for(int i = 0; i < M-1; i++) {
        for(int j = i+1; j < M; j++) {
            point = 0;
            for(int k = 0; k < N; k++) {
                point += max(A[k][i], A[k][j]);
            }
            max_point = max(max_point, point);
        }
    }

    cout << max_point << endl;
	return 0;
}