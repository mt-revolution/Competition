#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> idou = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool is_valid_island(vector<vector<char>> &board, vector<vector<bool>> &checked, int i, int j) {
    if (i <= -1 ||i >= 10 || j <= -1 || j >= 10) {
        return false;
    }

    if (board.at(i).at(j) == 'x') {
        return false;
    }

    if (checked.at(i).at(j) == true) {
        return false;
    }

    return true;
}

// 深さ優先探索
void fill_island(vector<vector<char>> &board, vector<vector<bool>> &checked, int i, int j) {
    checked.at(i).at(j) = true;

    for (int k = 0; k < 4; k++) {
        if(is_valid_island(board, checked, i + idou[k][0], j + idou[k][1]) == true) {
            fill_island(board, checked, i + idou[k][0], j + idou[k][1]);
        }
    }

}

// 地図を受け取って島が繋がっているか判断
bool is_island_connected(vector<vector<char>> &board) {
    vector<vector<bool>> checked(10, vector<bool>(10, false));
    vector<vector<bool>> ground(10, vector<bool>(10, false));
    int si, sj;

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(board.at(i).at(j) == 'o') {
                ground.at(i).at(j) = true;
                si = i, sj = j;
            }
        }
    }

    fill_island(board, checked, si, sj);
    
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(checked.at(i).at(j) != ground.at(i).at(j)) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    vector<vector<char>> A(10, vector<char>(10));
    bool finished = false;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> A.at(i).at(j);
        }
    }

    // 最初から条件を満たしていたとき
    if(is_island_connected(A) == true) {
        cout << "YES" << endl;
        return 0;
    } else {
        // 埋め立てるマスを全探索
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                // 埋め立ててみる
                if(A.at(i).at(j) == 'x') {
                    A.at(i).at(j) = 'o';

                    // いけたとき
                    if(is_island_connected(A) == true) {
                        cout << "YES" << endl;
                        return 0;
                    // ダメだったら戻す
                    } else {
                        A.at(i).at(j) = 'x';
                    }
                }
            }
        }
    }

    cout << "NO" << endl;
	return 0;
}