#include<bits/stdc++.h>

using namespace std;
int H, W;

bool is_valid_move(vector<vector<char>> &board, vector<vector<bool>> &checked, int x, int y) {
    if(x >= H || x < 0 || y >= W || y < 0) {
        return false;
    }

    if(checked.at(x).at(y) == true || board.at(x).at(y) == '#') {
        return false;
    }

    return true;
}

bool is_reachable(vector<vector<char>> &board, vector<vector<bool>> &checked, int x, int y) {
    checked.at(x).at(y) = true;

    if(board.at(x).at(y) == 'g') {
        return true;
    }

    if(is_valid_move(board, checked, x-1, y) == true) {
        if(is_reachable(board, checked, x-1, y) == true) {
            return true;
        }
    }

    if(is_valid_move(board, checked, x+1, y) == true) {
        if(is_reachable(board, checked, x+1, y) == true) {
            return true;
        }
    }

    if(is_valid_move(board, checked, x, y-1) == true) {
        if(is_reachable(board, checked, x, y-1) == true) {
            return true;
        }
    }

    if(is_valid_move(board, checked, x, y+1) == true) {
        if(is_reachable(board, checked, x, y+1) == true) {
            return true;
        }
    }

    return false;
} 

int main() {

    cin >> H >> W;

    vector<vector<char>> board(H, vector<char>(W));
    vector<vector<bool>> checked(H, vector<bool>(W, false));
    bool finished = false;

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> board.at(i).at(j);
        }
    }

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(board.at(i).at(j) == 's') {
                if(is_reachable(board, checked, i, j) == true) {
                    cout << "Yes" << endl;
                    finished = true;
                    break;
                } else {
                    cout << "No" << endl;
                    finished = true;
                    break;
                }
            }
        }

        if(finished == true) {
            break;
        }
    }

	return 0;
}