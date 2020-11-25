#include<bits/stdc++.h>

using namespace std;


int main() {
    int H, W, K;
    cin >> H >> W >> K;

    vector<vector<int>> c(H+2, vector<int>(W+2, 0));
    char in;

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> in;
            c[i][j] = in - '0';
        }
    }

    int answer = 0;
    vector<vector<int>> board(H+2, vector<int>(W+2, 0));

    for (int delete_i = 1; delete_i <= H; delete_i++) {
        for (int delete_j = 1; delete_j <= W; delete_j++) {
            board = c;

            for (int i = delete_i; i >= 1; i--) {
                board[i][delete_j] = board[i-1][delete_j];
            }

            int point = 0, tmp_number = 0, tmp_count = 0;
            bool combo = false;

            int increment = 0;

            // 連鎖する石が存在する限り続ける
            do {
                combo = false;

                for (int i = 1; i <= H; i++) {
                    tmp_number = 0, tmp_count = 0;

                    for (int j = 0; j < W+2; j++) {
                        // 前の石まででK個以上同じ石が連続したとき
                        if (tmp_count >= K) {
                            // 同じ石の場合
                            if (board[i][j] == tmp_number) {
                                tmp_count += 1;
                            
                            // 違う石の場合得点加算
                            } else {
                                combo = true;
                                point += tmp_number * tmp_count * (int)(pow(2.0, (float)increment));

                                // 石を1行下にずらす
                                for (int x = i; x >= 1; x--) {
                                    for (int y = j - tmp_count; y < j; y++) {
                                        board[x][y] = board[x-1][y]; 
                                    }
                                }

                                tmp_number = board[i][j];
                                tmp_count = 1;
                            }
                        } else {
                            if (board[i][j] == 0) {
                                tmp_number = 0;
                                tmp_count = 1;
                                continue;
                            }

                            if (board[i][j] == tmp_number) {
                                tmp_count += 1;
                            } else {
                                tmp_number = board[i][j];
                                tmp_count = 1;
                            }

                        }
                    }
                }

                increment++;
            } while (combo == true);

            answer = max(answer, point);
        }
    }

    cout << answer << endl;
    return 0;
}