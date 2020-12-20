#include<bits/stdc++.h>

using namespace std;
int H, W;

vector<vector<int>> idou = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// (x,y)に移動できるか
bool is_valid_move(vector<vector<char>> &board, vector<vector<bool>> &checked, int i, int j) {
    if(i >= H || i < 0 || j >= W || j < 0) {
        return false;
    }

    if(checked.at(i).at(j) == true || board.at(i).at(j) == '#') {
        return false;
    }

    return true;
}

// (x,y)から出発してゴールに辿り着けるか
bool is_reachable(vector<vector<char>> &board, vector<vector<bool>> &checked, int i, int j) {
    checked.at(i).at(j) = true;

    if(board.at(i).at(j) == 'g') {
        return true;
    }

    // 上下左右に移動できるなら移動する
    for (int k = 0; k < 4; k++) {
        if(is_valid_move(board, checked, i + idou[k][0], j + idou[k][1]) == true) {
            if(is_reachable(board, checked, i + idou[k][0], j + idou[k][1]) == true) {
                return true;
            }
        }
    }

    return false;
} 

int main() {
    cin >> H >> W;

    vector<vector<char>> board(H, vector<char>(W));
    vector<vector<bool>> checked(H, vector<bool>(W, false));
    int si, sj;

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> board.at(i).at(j);

            if (board[i][j] == 's') {
                si = i, sj = j;
            }
        }
    }

    if(is_reachable(board, checked, si, sj) == true) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

	return 0;
}