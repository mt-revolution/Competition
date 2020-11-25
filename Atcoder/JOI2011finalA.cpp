#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    int M, N, K;
    cin >> M >> N;
    cin >> K;
 
    vector<vector<char>> field(M, vector<char>(N));
 
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            cin >> field[i][j];
        }
    }
 
    vector<int> a(K), b(K), c(K), d(K);
 
    for(int i = 0; i < K; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
 
    vector<vector<int>> jungle(M+1, vector<int>(N+1, 0));
    vector<vector<int>> ocean(M+1, vector<int>(N+1, 0));
    vector<vector<int>> ice(M+1, vector<int>(N+1, 0));
 
    // 二次元累積和
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if(field[i][j] == 'J') {
                jungle[i+1][j+1] = jungle[i][j+1] + jungle[i+1][j] - jungle[i][j] + 1;
                ocean[i+1][j+1] = ocean[i][j+1] + ocean[i+1][j] - ocean[i][j];
                ice[i+1][j+1] = ice[i][j+1] + ice[i+1][j] - ice[i][j];
            } else if(field[i][j] == 'O') {
                ocean[i+1][j+1] = ocean[i][j+1] + ocean[i+1][j] - ocean[i][j] + 1;
                jungle[i+1][j+1] = jungle[i][j+1] + jungle[i+1][j] - jungle[i][j];
                ice[i+1][j+1] = ice[i][j+1] + ice[i+1][j] - ice[i][j];
            } else if(field[i][j] == 'I') {
                ice[i+1][j+1] = ice[i][j+1] + ice[i+1][j] - ice[i][j] + 1;
                jungle[i+1][j+1] = jungle[i][j+1] + jungle[i+1][j] - jungle[i][j];
                ocean[i+1][j+1] = ocean[i][j+1] + ocean[i+1][j] - ocean[i][j];
            }
        }
    }
 
    int numJ, numO, numI;
 
    for(int k = 0; k < K; k++) {       
        numJ = jungle[c[k]][d[k]] - jungle[a[k]-1][d[k]] - jungle[c[k]][b[k]-1] + jungle[a[k]-1][b[k]-1];
        numO = ocean[c[k]][d[k]] - ocean[a[k]-1][d[k]] - ocean[c[k]][b[k]-1] + ocean[a[k]-1][b[k]-1];
        numI = ice[c[k]][d[k]] - ice[a[k]-1][d[k]] - ice[c[k]][b[k]-1] + ice[a[k]-1][b[k]-1];
 
        cout << numJ << " " << numO << " " << numI << endl;
    }
 
	return 0;
}