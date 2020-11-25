#include<bits/stdc++.h>

using namespace std;

bool Queen_solve(vector<vector<char>> &board) {
    vector<int> row = {};
    vector<int> column = {};
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
    vector<int> row = {};
    vector<int> column = {};
    vector<int> r(k), c(k);
    int index;
    bool continued = false;

    for(int i = 0; i < k; i++) {
        cin >> r[i] >> c[i];
        board[r[i]][c[i]] = 'Q';
    }

    for(int i = 0; i < 8; i++) {
        continued = false;

        for(int j = 0; j < k; j++) {
            if(i == r[j]) {
                continued = true;
                break;
            }
        }

        if(continued == true) {
            continue;
        }
        row.push_back(i);
    }

    for(int i = 0; i < 8; i++) {
        continued = false;

        for(int j = 0; j < k; j++) {
            if(i == c[j]) {
                continued = true;
                break;
            }
        }

        if(continued == true) {
            continue;
        }
        column.push_back(i);
    }

    do {
        board_tmp = board;
        index = 0;

        for(int i : row) {
            board_tmp[i][column[index]] = 'Q';
            index++;
        }

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