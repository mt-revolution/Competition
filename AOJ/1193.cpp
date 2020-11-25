#include<bits/stdc++.h>

using namespace std;


int main() {
    int H;
    vector<int> answer;

    while (true) {
        cin >> H;

        if (H == 0) {
            break;
        }

        vector<vector<int>> board(H+2, vector<int>(7, 0));
        int point = 0, tmp_number = 0, tmp_count = 0;
        bool combo = false;

        for (int i = 1; i <= H; i++) {
            for (int j = 1; j <= 5; j++) {
                cin >> board[i][j];
            }
        }

        // 連鎖する石が存在する限り続ける
        do {
            combo = false;

            for (int i = 1; i <= H; i++) {
                tmp_number = 0, tmp_count = 0;

                for (int j = 0; j <= 6; j++) {
                    // 前の石までで3つ以上同じ石が連続したとき
                    if (tmp_count >= 3) {
                        // 同じ石の場合
                        if (board[i][j] == tmp_number) {
                            tmp_count += 1;
                        
                        // 違う石の場合得点加算
                        } else {
                            combo = true;
                            point += tmp_number * tmp_count;

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
        } while (combo == true);

        answer.push_back(point);
    }

    for (auto i : answer) {
        cout << i << endl;
    }
    return 0;
}