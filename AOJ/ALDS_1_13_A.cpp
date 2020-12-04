#include<bits/stdc++.h>

using namespace std;

bool Queen_solve(vector<vector<char>> &board) {
    vector<int> row;
    vector<int> column;
    int tmp_row, tmp_column;
    vector<vector<int>> move = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(board[i][j] == 'Q') {
                row.push_back(i);
                column.push_back(j);
            }
        }
    }

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 4; j++) {
            tmp_row = row[i];
            tmp_column = column[i];
            tmp_row += move[j][0];
            tmp_column += move[j][1];

            while(tmp_row >= 0 && tmp_row < 8 && tmp_column >= 0 && tmp_column < 8) {
                if(board[tmp_row][tmp_column] == 'Q') {
                    return false;
                }
                tmp_row += move[j][0];
                tmp_column += move[j][1];
            }
        }
    }

    return true;
}


int main() {
    int k;
    cin >> k;

    vector<vector<char>> board(8, vector<char>(8, '.'));
    vector<vector<char>> board_tmp;
    vector<int> row;
    vector<int> column;
    vector<int> id_row(8, 0), id_column(8, 0);
    int r,c;

    for(int i = 0; i < k; i++) {
        cin >> r >> c;
        id_row[r]++, id_column[c]++;
        board[r][c] = 'Q';
    }

    // 初期設定に含まれない行と列を選択
    for (int i = 0; i < 8; i++) {
        if (id_row[i] == 0) {
            row.push_back(i);
        }
        if (id_column[i] == 0) {
            column.push_back(i);
        }
    }

    // 解が見つかるまで行を基準に列を順列全探索
    do {
        board_tmp = board;

        for (int i = 0; i < row.size(); i++) {
            board_tmp[row[i]][column[i]] = 'Q';
        }

        // 現在の配置で条件を満たすか確認
        if(Queen_solve(board_tmp) == true) {
            break;
        }
    } while(next_permutation(column.begin(), column.end()));

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            cout << board_tmp[i][j];
        }
        cout << endl;
    }

	return 0;
}