#include<bits/stdc++.h>

using namespace std;

bool is_valid_island(vector<vector<char>> &board, vector<vector<bool>> &checked, int x, int y) {
    if (x <= -1 || x >= 10 || y <= -1 || y >= 10) {
        return false;
    }

    if (board.at(y).at(x) == 'x') {
        return false;
    }

    if (checked.at(y).at(x) == true) {
        return false;
    }

    return true;
}

void fill_island(vector<vector<char>> &board, vector<vector<bool>> &checked, int x, int y) {
    checked.at(y).at(x) = true;

    if(is_valid_island(board, checked, x, y-1) == true) {
        fill_island(board, checked, x, y-1);
    }
    if(is_valid_island(board, checked, x, y+1) == true) {
        fill_island(board, checked, x, y+1);
    }
    if(is_valid_island(board, checked, x-1, y) == true) {
        fill_island(board, checked, x-1, y);
    }
    if(is_valid_island(board, checked, x+1, y) == true) {
        fill_island(board, checked, x+1, y);
    }

}

bool is_island_connected(vector<vector<char>> &board) {
    bool finished = false;
    vector<vector<bool>> checked(10, vector<bool>(10, false));
    vector<vector<bool>> ground(10, vector<bool>(10, false));

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(board.at(i).at(j) == 'o') {
                ground.at(i).at(j) = true;
            }
        }
    }

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(board.at(i).at(j) == 'o') {
                fill_island(board, checked, j, i);
                finished = true;
                break;
            }
        }

        if(finished == true) {
            break;
        }
    }

    
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
    string result = "NO";

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> A.at(i).at(j);
        }
    }

    if(is_island_connected(A) == true) {
        result = "YES";
    } else {
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                if(A.at(i).at(j) == 'x') {
                    A.at(i).at(j) = 'o';
                    if(is_island_connected(A) == true) {
                        result = "YES";
                        finished = true;
                        break;
                    } else {
                        A.at(i).at(j) = 'x';
                    }
                }
            }

            if(finished == true) {
                break;
            }
        }
    }

    cout << result << endl;
	return 0;
}