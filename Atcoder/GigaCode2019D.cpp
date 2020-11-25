#include<bits/stdc++.h>

using namespace std;

int main() {
    int H,W;
    long long K,V;
    cin >> H >> W >> K >> V;

    vector<vector<long long>> A(H, vector<long long>(W));

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    vector<vector<long long>> A_cumu(H+1, vector<long long>(W+1, 0));

    // 二次元累積和
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            A_cumu[i+1][j+1] = A_cumu[i][j+1] + A_cumu[i+1][j] - A_cumu[i][j] + A[i][j];
        }
    }

    long long tmp, S, S_max = 0;

    // 左上(i,j)と右下(i+delta_i, j+delta_j)の長方形を考え、所持金が足りれば最大面積を更新
    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= W; j++) {
            for(int delta_i = 0; i + delta_i <= H; delta_i++) {
                for(int delta_j = 0; j + delta_j <= W; delta_j++) {
                    if((delta_i+1) * (delta_j+1) <= S_max) {
                        continue;
                    }

                    S = (delta_i+1) * (delta_j+1);
                    tmp = A_cumu[i+delta_i][j+delta_j] - A_cumu[i-1][j+delta_j] - A_cumu[i+delta_i][j-1] + A_cumu[i-1][j-1];

                    // 最大面積の更新
                    if(tmp + S*K <= V) {
                        S_max = S;
                    }
                }
            }
        }
    }

    cout << S_max << endl;
	return 0;
}