#include<bits/stdc++.h>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<char>> field(H+2, vector<char>(W+2, 'n'));
    vector<vector<int>> count_white(H+2, vector<int>(W+2, -1));
    queue<pair<int, int>> checked;
    int i, j;
    int count_black = 0;
    int answer = 0;

    vector<int> delta_i{-1, 1, 0, 0};
    vector<int> delta_j{0, 0, -1, 1};

    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= W; j++) {
            cin >> field[i][j];
            if(field[i][j] == '#') {
                count_black++;
            }
        }
    }
        

    // 初期化
    checked = {};
    
    count_white[1][1] = 1;
    checked.push(pair<int, int>(1, 1));

    while(checked.empty() == false) {
        i = checked.front().first;
        j = checked.front().second;
        checked.pop();

        for(int k = 0; k < 4; k++) {                
            if(field[i + delta_i[k]][j + delta_j[k]] == '.') {
                if(count_white[i + delta_i[k]][j + delta_j[k]] != -1) {
                    continue;
                } else {
                    count_white[i + delta_i[k]][j + delta_j[k]] = count_white[i][j] + 1;
                    checked.push(pair<int, int>(i + delta_i[k], j + delta_j[k]));
                }
            }
            
        }
    }

    // ゴール不可能な場合
    if(count_white[H][W] == -1) {
        answer = -1;

    // ゴール可能な場合
    } else {
        answer = H*W - count_black - count_white[H][W];
    }

    cout << answer << endl;
	return 0;
}